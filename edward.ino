/***************************************
 probably functional
 release notes:
 -added class map
 -scanning is happier :)
 -increased encapsulation
  * movement is now done through
    Robot, enforcing the updating
    of variables
***************************************/

// -1 = null; 0 = front; 1 = back; 2 = left; 3 = right

#include "robot.h" // defines class Robot
#include "scanWalls.h" // defines function scanWalls
#include "whichWays.h" // defines function whichWay
#include "debug.h" // what could this be used for?
#include <Servo.h>  // for motor

Robot Edward; // only instance used by main

void setup()  {
  Serial.begin(9600);
  // cannot be initialized in constructor because the constructor
  // is called before the arduino functions work
  // ping, head motor, l motor, r motor, l turn, r turn, move time, l zero, r zero
  Edward.start(7, 9, 3, 11, 750, 900, 2200);
  Edward.stop();
  Edward.Neck.write(90);
  debug("program start");
  // scan side behind robot. only needs to be done once
  // because every other time the robot has alreay moved
  // and so knows what is behind itself. This is in setup()
  // because it moves the wheels and so cannot be in scanWalls()
  Edward.turnRight();
  delay(100);
  // average five values for ping sensor
  byte dist[5] = {0, 0, 0, 0, 0};
  for(byte i = 0; i < 5; i++)  {
    dist[i] = Edward.Sensor.distance();
    delay(50);
    }
  byte ave = average(dist);
  if(ave > 0 && ave < 12)  {
    Edward.World.setWall(Edward.x(), Edward.y(), Edward.backOf());
    }
  delay(100);
  Edward.turnRight();
  
  debug("setup() finished");
  }

void loop()  {
  debug("loop() top");
    
  // if the walls haven't been scanned, scan them
  if(Edward.World.getMapped(Edward.x(), Edward.y()) == false)  {
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
    }
  // turn right
  if(nextSq == 1)  {
    debug("going right");
    Edward.turnRight();
    Edward.moveForward();
    }
  // u turn
  if(nextSq == 2)  {
    debug("going backwards");
    Edward.uTurn();
    Edward.moveForward();
    }
  // turn left
  if(nextSq == 3)  {
    debug("going left");
    Edward.turnLeft();
    Edward.moveForward();
    }
  
  // if backtracking, the way came is dead end
  if(Edward.backtracking == true)  {
    Edward.World.setDeadEnd(Edward.x(), Edward.y(), Edward.backOf());
    // am i done backtracking?  
    if(Edward.World.getNumSides(Edward.x(), Edward.y()) > 1)  {
      debug("done backtracking");
      Edward.backtracking = false;
      }
    }
    
  // the way came has been gone through
  Edward.World.setGoneThrough(Edward.x(), Edward.y(), Edward.backOf());
  
  // has robot gotten to all destinations?
  if(Edward.isFinished())  {
    debug("finished");
    while(true);
    }
  }
