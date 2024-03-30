#include "motor_armm.h"
#include <AFMotor.h>

void runArm1(AF_DCMotor motor){
    Serial.println("arm start");
    delay(200);
 
    motor.run(FORWARD);

    // wait for 260
    delay(260);

    motor.run(RELEASE);

    delay(100);

    // turn the motor on
    motor.run(BACKWARD);

    // wait for 267.5
    delay(270);

    // stop the motor
    motor.run(RELEASE);

  Serial.println("arm end");
}