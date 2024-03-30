#include "number_initialization.h"

int readNumber() {
  Serial.println("Insert number");
  while( Serial.available() == 0) {

  }
  int n = Serial.parseInt();
  Serial.println(n);
  while( Serial.available() != 0) {
    Serial.read();
  }
 return n;

}


void transformBinary(int number, int bNumber[]){
  for(int i = 3; number>0; number = number/2,i=i-1){
    bNumber[i] = number % 2;
    
  }
  
  
}