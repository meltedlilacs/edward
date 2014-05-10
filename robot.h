#ifndef robot.h
#define robot.h

#include <Servo.h>
#include "locomotion.h"
#include "squares.h"
#include "pingSensor.h"
#include "map.h"

/**************************************************************************
 this class combines classes MotorizedSensor, Locomotion, Zigbee and Map
 to create a functioning robot class. Map will mostly be used by methods
 in functions that do other things as well and will not have many access 
 functions. the contained classes have access functions because this 
 class will add functionality to many of them.
**************************************************************************/

class Robot  {
  public:
    // takes neck motor pin, left and right drive motor pins, and ping sensor pin. it also sets serial
    // baud rate and gets starting coordinates, ending coordinates and facing from the computer    
    void start(byte tempPingPin, byte tempMotorPin, byte tempLpin, byte tempRpin, unsigned int tempLeftTime, unsigned int tempRightTime, unsigned int tempMoveTime, byte tempLzero = 90, byte tempRzero = 90);
    
    // current facing
    byte frontOf() const;
    
    // left of current facing
    byte leftOf() const;
    
    // right of current facing
    byte rightOf() const;
    
    // back of current facing
    byte backOf() const;
    
    // current x coordinate
    byte x() const;
    
    // current y coordinate
    byte y() const;
    
    // destination x coordinate
    byte endX() const;
    
    // destination y coordinate
    byte endY() const;
    
    // side to relative direction conversion
    byte intToDir(byte side) const;
    
    byte dirToInt(byte dir) const;
    
    void moveForward();
    
    void turnLeft();
    
    void turnRight();
    
    void uTurn();

    void stop();
    
    boolean isFinished();
    
    boolean backtracking; // am i backtracking?

    PingSensor Sensor;
    Servo Neck;
    Map World;
    
    boolean moved;
    
    private:
      Locomotion Wheels;
      byte xPos; // x coordinate
      byte yPos; // y coordinate
      byte goals[3][2];
      byte currentGoal;
      byte numberGoals; // number of goals
      byte facing; // what direction am i facing?
      boolean finished;
  };

#endif
