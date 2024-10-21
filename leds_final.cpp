#include "Arduino.h"
#include "leds_final.h"


/*
    Made by Saku Kallioinen.
*/


void initializeLeds()
{
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
}

void setLed(byte ledNumber)
{
  if(ledNumber == 0) 
  {
    digitalWrite(A2, HIGH);
    digitalWrite(A3, LOW);
    digitalWrite(A4, LOW);
    digitalWrite(A5, LOW);
  }
  else if(ledNumber == 1)
  {
    digitalWrite(A3, HIGH);
    digitalWrite(A2, LOW);
    digitalWrite(A4, LOW);
    digitalWrite(A5, LOW);
  }
    else if(ledNumber == 2)
  {
    digitalWrite(A4, HIGH);
    digitalWrite(A3, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(A5, LOW);
  }
    else if(ledNumber == 3)
  {
    digitalWrite(A5, HIGH);
    digitalWrite(A3, LOW);
    digitalWrite(A4, LOW);
    digitalWrite(A2, LOW);
  }
}


void clearAllLeds()
{
 digitalWrite(A2, LOW);
 digitalWrite(A3, LOW);
 digitalWrite(A4, LOW);
 digitalWrite(A5, LOW);
}

void setAllLeds()
{
  digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  digitalWrite(A4, HIGH);
  digitalWrite(A5, HIGH);
}
