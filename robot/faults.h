#ifndef FAULTS_H
#define FAULTS_H
#include <Arduino.h>
#include <AFMotor.h>
#include <Adafruit_TCS34725.h>

bool bitsFault(int number);
bool colorFault(Adafruit_TCS34725 tcs);


#endif