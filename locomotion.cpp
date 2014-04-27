#include "locomotion.h"

/******************************
 class to coordinate the two
 drive wheels of the robot.
 the wheels are represented by
 class Servo from Servo.h
******************************/

// pass the pin numbers to be used
void Locomotion::start(byte Lpin, byte Rpin)  {
  Lzero = 90;
  Rzero = 90;
  
  if(Lzero < Rzero)  {
    LspeedDiff = Rzero - Lzero;
    RspeedDiff = 0;
    }
  if(Lzero > Rzero)  {
    LspeedDiff = 0;
    RspeedDiff = Lzero - Rzero;
    }
    
  // basic motor setup
  Lservo.attach(Lpin);
  Rservo.attach(Rpin);
    }
    
void Locomotion::moveForward()  {
  Lservo.write(117);
  Rservo.write(0);
  }

void Locomotion::turnLeft()  {
  Lservo.write(60);
  Rservo.write(10);
  }
  
// turn in place to the right
void Locomotion::turnRight()  {
  Lservo.write(180);
  Rservo.write(117);
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

