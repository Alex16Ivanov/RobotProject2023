#include "LED.H"

void ledBitsFault(int ledPin){
  digitalWrite(ledPin, HIGH);// turn the led on
  delay(1000);
  digitalWrite(ledPin, LOW);// turn the led on
  
  
}

void ledColorFault(int ledPin){
  digitalWrite(ledPin, HIGH);// turn the led on
  delay(1000);
  digitalWrite(ledPin, LOW);// turn the led on
}

void ledTimeFault(int ledPin){

  digitalWrite(ledPin, HIGH);// turn the led on
  delay(1000);
  digitalWrite(ledPin, LOW);// turn the led on
}