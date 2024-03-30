#ifndef SENSOR_H
#define SENSOR_H
#include <Arduino.h>
#include <AFMotor.h>
#include <Adafruit_TCS34725.h>



int readColor(Adafruit_TCS34725 tcs);
int readRedFont(Adafruit_TCS34725 tcs);
int readGreenFont(Adafruit_TCS34725 tcs);
int readBlueFont(Adafruit_TCS34725 tcs);

#endif