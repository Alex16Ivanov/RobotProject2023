
#include <AFMotor.h>
#include <Wire.h>
#include <Adafruit_TCS34725.h>


#include "number_initialization.h"
#include "sensor.h"

#include "motor_armm.h"

#include "motor_belt.h"
#include "motor_trap.h"
#include "led.h"
#include "faults.h"



//populni!
int armMotorPin = 1;
int beltMotorPin = 3;
int trapMotorPin = 2;
int ledPin1 = 2;
int ledPin2 = 9;
int ledPin3 = 10;

int number;
int bNumber[4] = {0,0,0,0};
int currBit = 0;
int currColor;
int neededColor;
// have we inputted a valid number
bool validNumber = false;
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
unsigned long timeStart;
unsigned long timeEnd;

// vij s kolko pin-a i kak se pravi
AF_DCMotor armMotor(armMotorPin, MOTOR12_1KHZ);
AF_DCMotor beltMotor(beltMotorPin, MOTOR12_1KHZ);
AF_DCMotor trapMotor(trapMotorPin, MOTOR12_1KHZ);

int rFont = 0;
int gFont= 0;
int bFont= 0;


void setup() {

  Serial.begin(9600);
  Serial.println("Working...");
  if (tcs.begin()) {
    Serial.println("Found TCS34725 sensor");
  } else {
    Serial.println("No TCS34725 sensor found");
    while (1);
  }
  
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  while(validNumber == false)
  {
    number = readNumber();
    if(bitsFault(number)){
      Serial.println("Invalid number");
      ledBitsFault(ledPin1);
    }
    else{
      validNumber = true;
      }
  }

  transformBinary(number,bNumber);
  for(int i = 0; i<4; i++){
    Serial.print(bNumber[i]);
  }
  Serial.println(" ");
  
  
  
  armMotor.setSpeed(250);
  beltMotor.setSpeed(250);
  trapMotor.setSpeed(250);


  
  timeStart = millis();

  
    // //while(rFont == 0 && bFont == 0 && gFont == 0){
    // rFont = readRedFont(tcs);
    // gFont = readGreenFont(tcs);
    // bFont = readBlueFont(tcs);
    // Serial.println(rFont);
    // Serial.println(gFont);
    // Serial.println(bFont);
    // //}
  
  
  
}

void loop() {
  neededColor = bNumber[currBit];
  currColor = readColor(tcs);
  
  Serial.println(currColor);

  // checks for different color and activates led light
  if(colorFault(tcs)){
    Serial.println("Unidentified object!!!");
    ledColorFault(ledPin2);
  }
  
  // after detecting the correct color
  if(neededColor == currColor){
    timeStart = millis();
    delay(1700);
    runArm1(armMotor);
    runBelt(beltMotor);
    currBit++;
    Serial.print("Bit is ");
    Serial.println(currBit);

    // when the box is full
    if(currBit == 4){
      Serial.println("The box is full");
      currBit = 0;
      
      // empties the box
      delay(10000);
      runTrap(trapMotor);
      
      runBeltBackward(beltMotor,4);
      
      validNumber = false;
      
      //operations to input new unmber
      while(validNumber == false)
      {
      number = readNumber();
      if(bitsFault(number)){
        Serial.println("Invalid number");
        ledBitsFault(ledPin1);
      }
      else{
        validNumber = true;
        }
      }

    transformBinary(number, bNumber);
    Serial.println("Bit is 0");
    timeStart = millis();
    }

    
  }
  else{
    timeEnd = millis();
    if(timeEnd-timeStart >= 180000){
      Serial.println("No required tokens detected for more than 3 minutes");
      ledTimeFault(ledPin3);
      runTrap(trapMotor);
      runBeltBackward(beltMotor,currBit);
      while(1);
    }
  }
  
}
