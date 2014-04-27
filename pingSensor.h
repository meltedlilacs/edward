#ifndef pingSensor.h
#define pingSensor.h

/****************************
 simple class to represent
 the ultrasonic ping sensor.
 The code to use the sensor
 was stolen from the "ping"
 example provided with the
 arduino IDE version 1.0.1
****************************/

class PingSensor  {
  public:
    // pass constructor the pin number to be used
    void start(int tempPingPin);
    
    // takes a reading and returns distance in inches
    long distance() const;
  
  private:
    byte pingPin; // pin num
  };
#endif


