#include "processing.h"
#include <Arduino.h>
#include <Serial.h>
#include "robot.h"
#include "map.h"

// for processing, of form x y sideone sidetwo sidethree sidefour facing backtracking (no spaces) with 0 = open, 1 = wall, 2 = dead end, 3 = gone through for the sides
void processing(Robot& aRobot) {
  String processing = String(aRobot.x()) + String(aRobot.y());
  if(aRobot.World.getWall(aRobot.x(), aRobot.y(), NORTH)) {
    processing += "1";
    }
  else if(aRobot.World.getDeadEnd(aRobot.x(), aRobot.y(), NORTH)) {
    processing += "2";
    }
  else if(aRobot.World.getGoneThrough(aRobot.x(), aRobot.y(), NORTH)) {
    processing += "3";
    }
  else {
    processing += "0";
    }
  if(aRobot.World.getWall(aRobot.x(), aRobot.y(), EAST)) {
    processing += "1";
    }
  else if(aRobot.World.getDeadEnd(aRobot.x(), aRobot.y(), EAST)) {
    processing += "2";
    }
  else if(aRobot.World.getGoneThrough(aRobot.x(), aRobot.y(), EAST)) {
    processing += "3";
    }
  else {
    processing += "0";
    }
  if(aRobot.World.getWall(aRobot.x(), aRobot.y(), SOUTH)) {
    processing += "1";
    }
  else if(aRobot.World.getDeadEnd(aRobot.x(), aRobot.y(), SOUTH)) {
    processing += "2";
    }
  else if(aRobot.World.getGoneThrough(aRobot.x(), aRobot.y(), SOUTH)) {
    processing += "3";
    }
  else {
    processing += "0";
    }
  if(aRobot.World.getWall(aRobot.x(), aRobot.y(), WEST)) {
    processing += "1";
    }
  else if(aRobot.World.getDeadEnd(aRobot.x(), aRobot.y(), WEST)) {
    processing += "2";
    }
  else if(aRobot.World.getGoneThrough(aRobot.x(), aRobot.y(), WEST)) {
    processing += "3";
    }
  else {
    processing += "0";
    }
  processing += String(enumToInt(aRobot.frontOf()));
  if(aRobot.backtracking == true) {
    processing += "1";
    }
  else {
    processing += "0";
    }
  Serial.println(processing);
  }
