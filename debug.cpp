#include "debug.h"

/********************************
 prints string to serial and
 awaits for any type of response
*********************************/

const boolean DEBUG = false;

void debug(String print_this) {
  if(DEBUG) {
  Serial.println(print_this);
  while(Serial.available() <= 0) {
    // waiting...
    }
  Serial.read(); // get those bytes out of the inbox
  }
  }
