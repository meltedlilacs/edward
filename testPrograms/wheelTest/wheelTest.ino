#include <Servo.h>

/******************************
 class to coordinate the two
 drive wheels of the robot.
 the wheels are represented by
 class Servo from Servo.h
******************************/

class Locomotion  {
  public:
    // pass the pin numbers to be used
    void start(byte Lpin, byte Rpin);
    
    // move one square forward
    void moveForward();
    
    // turn in place to the left
    void turnLeft();
    
    // turn in place to the right
    void turnRight();
    
    // u-turn clockwise
    void uTurn();
    
    void stop();
    
  private:
    Servo Lservo, Rservo;
    byte Lzero, Rzero; // the values that will stop the motors
    byte LspeedDiff, RspeedDiff;
  };

// pass the pin numbers to be used
void Locomotion::start(byte Lpin, byte Rpin)  {
  Lzero = 90;
  Rzero = 90;
  
  if(Lzero < Rzero)  {
    LspeedDiff = Rzero - Lzero;
    RspeedDiff = 0;
    }
  else if(Lzero > Rzero)  {
    LspeedDiff = 0;
    RspeedDiff = Lzero - Rzero;
    }
  else {
    LspeedDiff = 0;
    RspeedDiff = 0;
    }
    
    // basic motor setup
    Lservo.attach(Lpin);
    Rservo.attach(Rpin);
    }
    
void Locomotion::moveForward()  {
  Lservo.write(175);
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

Locomotion Wheels;
int rTurn = 900;
int lTurn = 750;
int moveTime = 2200;

void setup()  {
  Wheels.start(3, 11);
  Wheels.stop();
  delay(1000);
  }
  
void loop()  {
  // turn right
  Wheels.turnRight();
  delay(rTurn);
  Wheels.stop();
  
  delay(1000);
  
  // turn left
  Wheels.turnLeft();
  delay(lTurn);
  Wheels.stop();
  
  delay(1000);
  
  Wheels.moveForward();
  delay(moveTime);
  Wheels.stop();
  
  delay(1000);
  }
