/***************************************
 works. added checking to see if a
 square exists before moving to it
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
  Edward.start(7, 9, 3, 11, 750, 775, 2200);
  Edward.stop();
  Edward.Neck.write(90);
  debug("Press any key to start");
  }

void loop()  {
  // if the walls haven't been scanned, scan them
  if(Edward.World.getMapped(Edward.x(), Edward.y()) == false)  {
    scanWalls(Edward);
    }
  debug("Walls at (" + String(Edward.x()) + ", " + String(Edward.y()) + "): [" + String(Edward.World.getWall(Edward.x(), Edward.y(), NORTH)) + " " + String(Edward.World.getWall(Edward.x(), Edward.y(), EAST)) + " " + String(Edward.World.getWall(Edward.x(), Edward.y(), SOUTH)) + " " + String(Edward.World.getWall(Edward.x(), Edward.y(), WEST)) + "]");
  
  // for processing, of form x y sideone sidetwo sidethree sidefour (no spaces) with 0 = open, 1 = wall, 2 = dead end, 3 = gone through for the sides
  String processing = String(Edward.x()) + String(Edward.y());
  if(Edward.World.getWall(Edward.x(), Edward.y(), NORTH)) {
    processing += "1";
    }
  else if(Edward.World.getDeadEnd(Edward.x(), Edward.y(), NORTH)) {
    processing += "2";
    }
  else if(Edward.World.getGoneThrough(Edward.x(), Edward.y(), NORTH)) {
    processing += "3";
    }
  else {
    processing += "0";
    }
  if(Edward.World.getWall(Edward.x(), Edward.y(), EAST)) {
    processing += "1";
    }
  else if(Edward.World.getDeadEnd(Edward.x(), Edward.y(), EAST)) {
    processing += "2";
    }
  else if(Edward.World.getGoneThrough(Edward.x(), Edward.y(), EAST)) {
    processing += "3";
    }
  else {
    processing += "0";
    }
  if(Edward.World.getWall(Edward.x(), Edward.y(), SOUTH)) {
    processing += "1";
    }
  else if(Edward.World.getDeadEnd(Edward.x(), Edward.y(), SOUTH)) {
    processing += "2";
    }
  else if(Edward.World.getGoneThrough(Edward.x(), Edward.y(), SOUTH)) {
    processing += "3";
    }
  else {
    processing += "0";
    }
  if(Edward.World.getWall(Edward.x(), Edward.y(), WEST)) {
    processing += "1";
    }
  else if(Edward.World.getDeadEnd(Edward.x(), Edward.y(), WEST)) {
    processing += "2";
    }
  else if(Edward.World.getGoneThrough(Edward.x(), Edward.y(), WEST)) {
    processing += "3";
    }
  else {
    processing += "0";
    }
  Serial.println(processing);

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
