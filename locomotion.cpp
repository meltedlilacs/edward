#include "locomotion.h"

/******************************
 class to coordinate the two
 drive wheels of the robot.
 the wheels are represented by
 class Servo from Servo.h
******************************/

// pass the pin numbers to be used
void Locomotion::start(byte Lpin, byte Rpin, unsigned int tempLeftTime, unsigned int tempRightTime, unsigned int tempMoveTime, byte tempLzero, byte tempRzero)  {
  Lzero = tempLzero;
  Rzero = tempRzero;

  leftTime = tempLeftTime;
  rightTime = tempRightTime;
  moveTime = tempMoveTime;
    
  // basic motor setup
  Lservo.attach(Lpin);
  Rservo.attach(Rpin);
  }

void Locomotion::moveForward()  {
  Lservo.write(170);
  Rservo.write(10);
  delay(moveTime);
  stop();
  }

void Locomotion::turnLeft()  {
  Lservo.write(60);
  Rservo.write(10);
  delay(leftTime);
  stop();
  }
  
// turn in place to the right
void Locomotion::turnRight()  {
  Lservo.write(180);
  Rservo.write(117);
  delay(rightTime);
  stop();
  }
  
// u-turn clockwise
void Locomotion::uTurn()  {
  turnRight();
  turnRight();
  }
  
void Locomotion::stop()  {
  Lservo.write(Lzero);
  Rservo.write(Rzero);
  }

