#include "robot.h"
#include "debug.h"
#include "enums.h"

/**************************************************************************
 this class combines classes MotorizedSensor, Locomotion, Zigbee and Map
 to create a functioning robot class. Map will mostly be used by methods
 in functions that do other things as well and will not have many access 
 functions. the contained classes have access functions because this 
 class will add functionality to many of them.
**************************************************************************/
  
// takes neck motor pin, left and right drive motor pins, and ping sensor pin. it also sets serial 
// baud rate and gets starting coordinates, ending coordinates and facing from the computer
void Robot::start(byte tempPingPin, byte tempMotorPin, byte tempLpin, byte tempRpin, unsigned int tempLeftTime, unsigned int tempRightTime, unsigned int tempMoveTime, byte tempLzero, byte tempRzero)  {
  Sensor.start(tempPingPin);
  Neck.attach(tempMotorPin);
  Wheels.start(tempLpin, tempRpin, tempLeftTime, tempRightTime, tempMoveTime, tempLzero, tempRzero);
  backtracking = false;
  xPos = 0;
  yPos = 0;
  goals[0][0] = 0;
  goals[0][1] = 0;
  goals[1][0] = 1;
  goals[1][1] = 4;
  goals[2][0] = 0;
  goals[2][1] = 0;
  currentGoal = 1;
  facing = NORTH;
  finished = false;
  numberGoals = 3;
  }
  
// current facing
compassDir Robot::frontOf() const  {
  return facing;
  }
  
// left of current facing
compassDir Robot::leftOf() const  {
  switch(facing)  {
    case NORTH:
      return WEST;
      break;
    case EAST:
      return NORTH;
      break;
    case SOUTH:
      return EAST;
      break;
    case WEST:
      return SOUTH;
      break;
    }
  }

// right of current facing
compassDir Robot::rightOf() const  {
  switch(facing)  {
    case NORTH:
      return EAST;
      break;
    case EAST:
      return SOUTH;
      break;
    case SOUTH:
      return WEST;
      break;
    case WEST:
      return NORTH;
      break;
    }
  }

// back of current facing
compassDir Robot::backOf() const  {
  switch(facing)  {
    case NORTH:
      return SOUTH;
      break;
    case EAST:
      return WEST;
      break;
    case SOUTH:
      return NORTH;
      break;
    case WEST:
      return EAST;
      break;
    }
  }
    
// current x coordinate
byte Robot::x() const  {
  return xPos;
  }

// current y coordinate
byte Robot::y() const  {
  return yPos;
  }

// destination x coordinate
byte Robot::endX() const  {
  return goals[currentGoal][0];
  }

// destination y coordinate
byte Robot::endY() const  {
  return goals[currentGoal][1];
  }

// compass to relative conversion
relativeDir Robot::compassToRelative(compassDir side) const  {
  if(side == frontOf())  {
    return FRONT;
    }
  if(side == rightOf())  {
    return RIGHT;
    }
  if(side == backOf())  {
    return BACK;
    }
  if(side == leftOf())  {
    return LEFT;
    }
  }

// relative direction to compass
compassDir Robot::relativeToCompass(relativeDir dir) const  {
  switch(facing)  {
    case NORTH:
      switch(dir)  {
        case FRONT:
          return NORTH;
          break;
        case RIGHT:
          return EAST;
          break;
        case BACK:
          return SOUTH;
          break;
        case LEFT:
          return WEST;
          break;
        }
      break;
    case EAST:
      switch(dir)  {
        case FRONT:
          return WEST;
          break;
        case RIGHT:
          return SOUTH;
          break;
        case BACK:
          return EAST;
          break;
        case LEFT:
          return NORTH;
          break;
        }
      break;
    case SOUTH:
      switch(dir)  {
        case FRONT:
          return SOUTH;
          break;
        case RIGHT:
          return WEST;
          break;
        case BACK:
          return NORTH;
          break;
        case LEFT:
          return EAST;
          break;
        }
      break;
    case WEST:
      switch(dir)  {
        case FRONT:
          return WEST;
          break;
        case RIGHT:
          return NORTH;
          break;
        case BACK:
          return EAST;
          break;
        case LEFT:
          return SOUTH;
          break;
        }
      break;
    }
  }
  
// Locomotion access functions

void Robot::moveForward()  {
  moved = true;
  Wheels.moveForward();
  switch(facing)  {
    case NORTH:
      yPos++;
      break;
    case EAST:
      xPos++;
      break;
    case SOUTH:
      yPos--;
      break;
    case WEST:
      xPos--;
      break;
    }
  if(x() == endX() && y() == endY()) {
    //debug("Reached destination (" + String(xPos) + ", " + String(yPos) + ")");
    debug("Reached destination");
    }
  // if at destination, find next good destination
  while((x() == endX() && y() == endY()) || goals[currentGoal][0] < 0 || goals[currentGoal][1] < 0)  {
    currentGoal++;
    //debug("New goal: " + String(currentGoal));
    if(currentGoal > numberGoals - 1)  { // minus one because currentGoal is zero indexed
      finished = true;
      break;
      }
    }
  }
  
void Robot::turnLeft()  {
  moved = true;
  Wheels.turnLeft();
  switch(facing) {
    case NORTH:
      facing = WEST;
      break;
    case EAST:
      facing = NORTH;
      break;
    case SOUTH:
      facing = EAST;
      break;
    case WEST:
      facing = SOUTH;
      break;
    }
  }
  
void Robot::turnRight()  {
  moved = true;
  Wheels.turnRight();
  switch(facing) {
    case NORTH:
      facing = EAST;
      break;
    case EAST:
      facing = SOUTH;
      break;
    case SOUTH:
      facing = WEST;
      break;
    case WEST:
      facing = NORTH;
      break;
    }
  }
  
void Robot::uTurn()  {
  moved = true;
  Wheels.uTurn();
  switch(facing) {
    case NORTH:
      facing = SOUTH;
      break;
    case EAST:
      facing = WEST;
      break;
    case SOUTH:
      facing = NORTH;
      break;
    case WEST:
      facing = EAST;
      break;
    }
  }

void Robot::stop() {
  Wheels.stop();
  }

boolean Robot::isFinished() {
  return finished;
  }
