#include <Servo.h>
 
Servo servoLeft;
Servo servoRight;
 
const int servoLeftPin = 8;
const int servoRightPin = 9;
 
const int degreeDelay = 10;
int roundCount = 0; //counter track how many times the lifting motion will run
 
void setup() {
  servoLeft.attach(servoLeftPin);
  servoRight.attach(servoRightPin);
 
  servoLeft.write(0);
  servoRight.write(145);
  delay(1000);
}
 
void loop() {
  if(roundCount < 2){
  // Move both servos from 0° to 182
  for (int pos = 0; pos <= 145; pos++) {
    servoLeft.write(pos);
    servoRight.write(145 - pos); // Opposite direction, optional delay(degreeDelay);
    }
 
  delay(500); // pause at top
  
  
  // Move both servos back from 90° to 0°
  for (int pos = 145; pos >= 0; pos--) {
    servoLeft.write(pos);
    servoRight.write(145 - pos); // move back opposite
    delay(degreeDelay);
  }
 
  delay(6000);
  // pause before next cycle
  roundCount++;
  }
}


//Angle can be changed due to testing and validation
