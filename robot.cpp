#include "robot.h"

/**************************************************************************
 this class combines classes MotorizedSensor, Locomotion, Zigbee and Map
 to create a functioning robot class. Map will mostly be used by methods
 in functions that do other things as well and will not have many access 
 functions. the contained classes have access functions because this 
 class will add functionality to many of them.
**************************************************************************/
  
// takes neck motor pin, left and right drive motor pins, and ping sensor pin. it also sets serial 
// baud rate and gets starting coordinates, ending coordinates and facing from the computer
void Robot::start(byte tempPingPin, byte tempMotorPin, byte tempLpin, byte tempRpin)  {
  Sensor.start(tempPingPin);
  Neck.attach(tempMotorPin);
  Wheels.start(tempLpin, tempRpin);
  backtracking = false;
  xPos = 0;
  yPos = 0;
  goals[0][0] = xPos;
  goals[0][1] = yPos;
  goals[1][0] = 1;
  goals[1][1] = 4;
  goals[2][0] = xPos;
  goals[2][1] = yPos;
  currentGoal = 1;
  facing = 0;
  }

  
// current position
Square* Robot::location()  {
//  return Array.member(xPos, yPos);
  return &Array[xPos][yPos];
  }
  
// destination location
Square* Robot::endPosition()  {
  return &Array[goals[currentGoal][0]][goals[currentGoal][1]];
  }
  
// current facing
byte Robot::frontOf() const  {
  return facing;
  }
  
// left of current facing
byte Robot::leftOf() const  {
  switch(facing)  {
    case 0:
      return 3;
      break;
    case 1:
      return 0;
      break;
    case 2:
      return 1;
      break;
    case 3:
      return 2;
      break;
    }
  }

// right of current facing
byte Robot::rightOf() const  {
  switch(facing)  {
    case 0:
      return 1;
      break;
    case 1:
      return 2;
      break;
    case 2:
      return 3;
      break;
    case 3:
      return 0;
      break;
    }
  }

// back of current facing
byte Robot::backOf() const  {
  switch(facing)  {
    case 0:
      return 2;
      break;
    case 1:
      return 3;
      break;
    case 2:
      return 0;
      break;
    case 3:
      return 1;
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

// side to relative direction conversion
byte Robot::intToDir(byte side) const  {
  if(side == frontOf())  {
    return 0;
    }
  if(side == rightOf())  {
    return 1;
    }
  if(side == backOf())  {
    return 2;
    }
  if(side == leftOf())  {
    return 3;
    }
  }

byte Robot::dirToInt(byte dir) const  {
  switch(facing)  {
    case 0:
      return dir;
      break;
    case 1:
      switch(dir)  {
        case 0:
          return 3;
          break;
        case 1:
          return 2;
          break;
        case 2:
          return 1;
          break;
        case 3:
          return 0;
          break;
        }
      break;
    case 2:
      switch(dir)  {
        case 0:
          return 2;
          break;
        case 1:
          return 3;
          break;
        case 2:
          return 0;
          break;
        case 3:
          return 1;
          break;
        }
      break;
    case 3:
      switch(dir)  {
        case 0:
          return 3;
          break;
        case 1:
          return 0;
          break;
        case 2:
          return 1;
          break;
        case 3:
          return 0;
          break;
        }
      break;
    }
  }
  
// Locomotion access functions

void Robot::moveForward()  {
  moved = true;
  switch(facing)  {
    case 0:
      yPos++;
      break;
    case 1:
      xPos++;
      break;
    case 2:
      yPos--;
      break;
    case 3:
      xPos--;
      break;
    }
  // if at destination, find next good destination
  while(location() == endPosition() || goals[currentGoal][0] < 0 || goals[currentGoal][1] < 0)  {
    currentGoal++;
    if(currentGoal > 2)  {
      break;
      }
    }
  }
  
void Robot::turnLeft()  {
  moved = true;
  // update direction variable:
  if(facing == 0)  {
    facing = 3;
    }
  else  {
    facing--;
    }
  }
  
void Robot::turnRight()  {
  moved = true;
  // update direction variable:
  if(facing == 3)  {
    facing = 0;
    }
  else  {
    facing++;
    }
  }
  
void Robot::uTurn()  {
  moved = true;
  // update direction variable:
  switch(facing)  {
    case(0):
      facing = 2;
      break;
    case(1):
      facing = 3;
      break;
    case(2):
      facing = 0;
      break;
    case(3):
      facing = 1;
      break;
    }
  }