#include "debug.h"

/********************************
 prints string to serial and
 awaits for any type of response
*********************************/

// 0 = no pausing, 1 = pause for important stuff, 2 = pause for everything
const byte DEBUG = 1;

void debug(String print_this, boolean important) {
  Serial.println(print_this);
  if(DEBUG == 2 || (important && DEBUG == 1)) {
    while(Serial.available() <= 0) {
      // waiting...
      }
    Serial.read(); // get those bytes out of the inbox
    }
  }
