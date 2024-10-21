#ifndef DISPLAY_H
#define DISPLAY_H
#include <arduino.h>


/*
    Made by Danil Akhmetshin and Sofiia Pliushch.
*/


// MR pin sets register's values to zero
const uint8_t reset = 12;
// SHCP pin recieves ticks signal
const uint8_t shiftClock = 11;
// latch (STCP) pin represents data transferring interval
const uint8_t latchClock = 10;
// while OE pin is LOW enables Q0-Q7 outputs
const uint8_t outEnable = 9;
// binary data is sent to this pin
const uint8_t serialInput = 8;

// 7-SEGMENT COMMON ANODE DISPLAY USES THESE 8-BIT CODES FOR NUMBER REPRESENTATION
const uint8_t digits[] = {
  	0b00000011,
	0b10011111,
  	0b00100101,
  	0b00001101,
  	0b10011001,
  	0b01001001,
  	0b01000001,
  	0b00011111,
  	0b00000001,
  	0b00011001
};

/*
  initializeDisplay subroutine initializes 5 pins needed for controlling 7-segment
  displays in a cascade as follows:
  Arduino pin 12 = serial to parallel component reset
  Arduino pin 11 = serial to parallel component shiftClock
  Arduino pin 10 = serial to parallel component latchClock
  Arduino pin 9  = serial to parallel component outEnable
  Arduino pin 8  = serial to parallel component serialInput
*/
void initializeDisplay(void);

/*
  WriteByte subroutine sends data to shift registers and writes number 0,1,...,9 to
  7-segment display.
  
  Parameters:
  uint8_t number: accepts values 0,1,..,9
*/
void writeByte(uint8_t number);

/*
  writeHighAndLowNumber subroutine writes a number 0,1,..,99
  to 2 cascaded 7-segment displays. This subroutine uses
  WriteByte subroutine to write 2 numbers to the display.
  If number is less than 10 clears display and prints only ones.
  
  Parameters:
  
  uint8_t tens: number 0,1,..,9
  uint8_t ones: number 0,1,..,9
  
*/
void writeHighAndLowNumber(uint8_t tens,uint8_t ones);

/*
  showResuts(uint8_t result) This function separates tens and ones
  from a result number and calls writeHighAndLowNumber subroutine
  to actually write the number to 7-segment display.
  
  Parameters:
  uint8_t result: A number between 0,1,..,99.
*/
void showResult(uint8_t result);

/*
    Clears display
*/
void clearDisplay(void);

#endif
