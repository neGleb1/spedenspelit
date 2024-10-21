#include "display_final.h"


/*
    Made by Danil Akhmetshin and Sofiia Pliushch.
*/


void initializeDisplay(void)
{
    pinMode(reset, OUTPUT);
    pinMode(shiftClock, OUTPUT);
    pinMode(latchClock, OUTPUT);
    pinMode(outEnable, OUTPUT);
    pinMode(serialInput, OUTPUT);   
    digitalWrite(reset, 1);
    digitalWrite(outEnable, 0);
    clearDisplay();
}

void clearDisplay()
{
  writeByte(0b11111111);
  writeByte(0b11111111);
}

void showResult(uint8_t number)
{
    writeHighAndLowNumber(number/10, number%10);
}

void writeHighAndLowNumber(uint8_t tens,uint8_t ones)
{
    if (tens == 0){
        clearDisplay();
        writeByte(digits[ones]);
    } else {
        writeByte(digits[tens]);
        writeByte(digits[ones]);
    }
}

void writeByte(uint8_t data) {
    digitalWrite(latchClock, 0);
    digitalWrite(serialInput, 0);
    digitalWrite(shiftClock, 0);
    for (int i=0; i<8; i++)  {
      digitalWrite(shiftClock, 0);
      ((data>>i) & 1) ? digitalWrite(serialInput, 1) : digitalWrite(serialInput, 0);
      digitalWrite(shiftClock, 1);
      digitalWrite(shiftClock, 0);
    }
    digitalWrite(shiftClock, 0);
    digitalWrite(latchClock, 1);
}

