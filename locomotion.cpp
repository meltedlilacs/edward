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
  delay(50);
  Lservo.write(175);
  Rservo.write(0);
  delay(moveTime);
  stop();
  }

void Locomotion::turnLeft()  {
  delay(50);
  Lservo.write(60);
  Rservo.write(10);
  delay(leftTime);
  stop();
  }
  
// turn in place to the right
void Locomotion::turnRight()  {
  delay(50);
  Lservo.write(180);
  Rservo.write(117);
  delay(rightTime);
  stop();
  }
  
// u-turn clockwise
void Locomotion::uTurn()  {
  delay(50);
  turnRight();
  turnRight();
  }
  
void Locomotion::stop()  {
  delay(50);
  Lservo.write(Lzero);
  Rservo.write(Rzero);
  }

