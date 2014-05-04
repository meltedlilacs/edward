#include "debug.h"

/********************************
 prints string to serial and
 awaits for any type of response
*********************************/

const boolean DEBUG = true;

void debug(String print_this) {
  Serial.println(print_this);
  if(DEBUG) {
    while(Serial.available() <= 0) {
      // waiting...
      }
    Serial.read(); // get those bytes out of the inbox
    }
  }
