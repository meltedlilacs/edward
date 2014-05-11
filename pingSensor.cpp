#include <Arduino.h>
#include "pingSensor.h"

/****************************
 simple class to represent
 the ultrasonic ping sensor.
 The code to use the sensor
 was stolen from the "ping"
 example provided with the
 arduino IDE version 1.0.1
****************************/

// pass constructor the pin number to be used
void PingSensor::start(int tempPingPin)  {
  pingPin = tempPingPin;
  }

// takes a reading and returns distance in inches  
long PingSensor::distance() const  {
  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  long duration = pulseIn(pingPin, HIGH); // get length
  long inches = duration / 74 / 2; // get distance
  return inches;
  }

