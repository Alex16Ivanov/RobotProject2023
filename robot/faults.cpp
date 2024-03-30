#include "FAULTS.h"
#include "SENSOR.H" // or sensor.h?

bool bitsFault(int number){
  if(number<0 || number > 15){
    return true;
  }
  else {
    return false;
  }

}

bool colorFault(Adafruit_TCS34725 tcs){
  if(readColor(tcs)==-1){
    return true;
  }
  else{
    return false;
  }
}

