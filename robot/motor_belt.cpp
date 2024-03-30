#include "motor_belt.h"
#include <AFMotor.h>


void runBelt(AF_DCMotor motor){
  Serial.println("belt start");
  // turn the motor on
    motor.run(FORWARD);

    // wait for 1 seconds
    delay(360);

    motor.run(RELEASE);

    Serial.println("belt end");
}

void runBeltBackward(AF_DCMotor motor,int tBack){
  Serial.println("BeltBack start");
  // turn the motor on
    motor.run(BACKWARD);

    // wait for 1 seconds
    delay(tBack*337);

    motor.run(RELEASE);
    Serial.println("BeltBack end");

    
}