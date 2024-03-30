#include "motor_trap.h"
#include <AFMotor.h>

void runTrap(AF_DCMotor motor){
   Serial.println("Trap start");
    // turn the motor on
    motor.run(FORWARD);

    // wait for 1 seconds
    delay(270);

    motor.run(RELEASE);


    delay(1000);
    // turn the motor on
    motor.run(BACKWARD);

    // wait for 1 seconds
    delay(400);

    // stop the motor
    motor.run(RELEASE);

    Serial.println("Trap end");

}