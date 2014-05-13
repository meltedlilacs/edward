#include <Servo.h> 
 
Servo lServo;
Servo rServo;
 
int pos = 0;
 
void setup() {
  lServo.attach(3);
  rServo.attach(11);
  Serial.begin(9600);
  }

void loop() {
  for(pos = 0; pos < 180; pos += 1) {
    lServo.write(pos);
    rServo.write(pos);
    Serial.println(pos);
    delay(15);
    } 
  for(pos = 180; pos>=1; pos-=1) {                                
    lServo.write(pos);
    rServo.write(pos);
    Serial.println(pos);
    delay(15);
    }
  }