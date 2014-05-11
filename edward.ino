/***************************************
 might work.
 adding enums
***************************************/

#include "robot.h" // defines class Robot
#include "scanWalls.h" // defines function scanWalls
#include "whichWays.h" // defines function whichWay
#include "debug.h" // what could this be used for?
#include <Servo.h>  // for motor
#include "enums.h"

Robot Edward; // only instance used by main

void setup()  {
  Serial.begin(9600);
  // cannot be initialized in constructor because the constructor
  // is called before the arduino functions work
  // ping, head motor, l motor, r motor, l turn, r turn, move time, l zero, r zero
  Edward.start(7, 9, 3, 11, 700, 800, 2200);
  Edward.stop();
  Edward.Neck.write(90);
  debug("Press any key to start");
  // scan side behind robot. only needs to be done once
  // because every other time the robot has alreay moved
  // and so knows what is behind itself. This is in setup()
  // because it moves the wheels and so cannot be in scanWalls()
  Edward.uTurn();
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
  Edward.uTurn();
  }

void loop()  {
  // if the walls haven't been scanned, scan them
  if(Edward.World.getMapped(Edward.x(), Edward.y()) == false)  {
    scanWalls(Edward);
    }
  debug("Walls at (" + String(Edward.x()) + ", " + String(Edward.y()) + "): [" + String(Edward.World.getWall(Edward.x(), Edward.y(), NORTH)) + " " + String(Edward.World.getWall(Edward.x(), Edward.y(), EAST)) + " " + String(Edward.World.getWall(Edward.x(), Edward.y(), SOUTH)) + " " + String(Edward.World.getWall(Edward.x(), Edward.y(), WEST)) + "]");
  // get best route
  relativeDir nextSq = Edward.compassToRelative(whichWay(Edward));
  debug("Going in direction " + toString(nextSq));
  
  // am i backtracking?
  if(nextSq == BACK)  {
    debug("Now backtracking");
    Edward.backtracking = true;
    }
  
  // follow the best route
  // go forward
  if(nextSq == FRONT)  {
    Edward.moveForward();
    }
  // turn right
  if(nextSq == RIGHT)  {
    Edward.turnRight();
    Edward.moveForward();
    }
  // u turn
  if(nextSq == BACK)  {
    Edward.uTurn();
    Edward.moveForward();
    }
  // turn left
  if(nextSq == LEFT)  {
    Edward.turnLeft();
    Edward.moveForward();
    }
  
  // if backtracking, the way came is dead end
  if(Edward.backtracking == true)  {
    Edward.World.setDeadEnd(Edward.x(), Edward.y(), Edward.backOf());
    // am i done backtracking?  
    if(Edward.World.getNumSides(Edward.x(), Edward.y()) > 1)  {
      debug("No longer backtracking");
      Edward.backtracking = false;
      }
    }
  
  debug("Now at (" + String(Edward.x()) + ", " + String(Edward.y()) + ")");

  // the way came has been gone through
  Edward.World.setGoneThrough(Edward.x(), Edward.y(), Edward.backOf());
  
  // has robot gotten to all destinations?
  if(Edward.isFinished())  {
    debug("Reached all goals");
    while(true);
    }
  }
