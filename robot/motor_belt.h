#ifndef MOTOR_BELT_H
#define MOTOR_BELT_H
#include <Arduino.h>
#include <AFMotor.h>


void runBelt(AF_DCMotor motor);
void runBeltBackward(AF_DCMotor motor, int tBack);


#endif