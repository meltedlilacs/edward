/***************************************
 probably functional
 release notes:
 -reverted whichWay
***************************************/

// -1 = null; 0 = front; 1 = back; 2 = left; 3 = right

#include "robot.h" // defines class Robot
#include "scanWalls.h" // defines function scanWalls
#include "whichWays.h" // defines function whichWay
#include "debug.h" // what could this be used for?
#include <Servo.h>  // for motor

Robot Edward; // only instance used by main
int rTurn = 760;
int lTurn = 690;
int moveTime = 2240;

void setup()  {
  Serial.begin(9600);
  // cannot be initialized in constructor because the constructor
  // is called before the arduino functions work
  // ping, head motor, l motor, r motor
  Edward.start(7, 9, 3, 11);
  Edward.Wheels.stop();
  Edward.Neck.write(90);
  delay(100);
  // scan side behind robot. only needs to be done once
  // because every other time the robot has alreay moved
  // and so knows what is behind itself. This is in setup()
  // because it moves the wheels and so cannot be in scanWalls()
  Edward.Wheels.turnRight();
  delay(rTurn * 2);
  Edward.Wheels.stop();
  delay(100);
  // average five values for ping sensor
  byte dist[5] = {0, 0, 0, 0, 0};
  Edward.Neck.write(90);
  for(byte i = 0; i < 5; i++)  {
    dist[i] = Edward.Sensor.distance();
    delay(50);
    }
  byte ave = average(dist);
  if(ave > 0 && ave < 12)  {
    Edward.location()->setWall(Edward.backOf());
    }
  delay(100);
  Edward.Wheels.turnRight();
  delay(rTurn * 2);
  Edward.Wheels.stop();
  
  debug("setup() finished");
  }

void loop()  {
  debug("loop() top");
  // has robot gotten to destination?
  if(Edward.location() == Edward.endPosition())  {
    debug("at destination");
    delay(100);
    Edward.Wheels.turnRight();
    delay(rTurn * 4);
    Edward.Wheels.stop();
    while(true);
    }
  
  // if the walls haven't been scanned, scan them
  if(Edward.location()->mapped == false)  {
    debug("scanning walls");
    scanWalls(Edward);
    }
  
  // get best route
  byte nextSq = whichWay(Edward);
  debug("nextSq: " + nextSq);
  
  // am i backtracking?
  if(nextSq == 2)  {
    debug("backtracking");
    Edward.backtracking = true;
    }
  
  // follow the best route
  // go forward
  if(nextSq == 0)  {
    debug("going forward");
    Edward.moveForward();
    Edward.Wheels.moveForward();
    delay(moveTime);
    Edward.Wheels.stop();
    }
  // turn right
  if(nextSq == 1)  {
    debug("going right");
    Edward.turnRight();
    Edward.Wheels.turnRight();
    delay(rTurn);
    Edward.Wheels.stop();
    Edward.moveForward();
    Edward.Wheels.moveForward();
    delay(moveTime);
    Edward.Wheels.stop();
    }
  // u turn
  if(nextSq == 2)  {
    debug("going backwards");
    Edward.uTurn();
    Edward.Wheels.turnRight();
    delay(rTurn * 2);
    Edward.Wheels.stop();
    Edward.moveForward();
    Edward.Wheels.moveForward();
    delay(moveTime);
    Edward.Wheels.stop();
    }
  // turn left
  if(nextSq == 3)  {
    debug("going left");
    Edward.turnLeft();
    Edward.Wheels.turnLeft();
    delay(lTurn);
    Edward.Wheels.stop();
    Edward.moveForward();
    Edward.Wheels.moveForward();
    delay(moveTime);
    Edward.Wheels.stop();
    }
  
  // if backtracking, the way came is dead end
  if(Edward.backtracking == true)  {
    Edward.location()->setDeadEnd(Edward.backOf());
    // am i done backtracking?  
    if(Edward.location()->getNumSides() > 1)  {
      debug("done backtracking");
      Edward.backtracking = false;
      }
    }
    
  // the way came has been gone through
  Edward.location()->setGoneThrough(Edward.backOf());
  }
