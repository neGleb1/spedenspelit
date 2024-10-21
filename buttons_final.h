#ifndef BUTTONS_H
#define BUTTONS_H
#include <arduino.h>


/*
    Made by Danil Akhmetshin.
*/


/*
    Button pins
*/
const int btn1 = 2;
const int btn2 = 3;
const int btn3 = 4;
const int btn4 = 5;
const int buttons[] = {2, 3, 4, 5};
const int start_game_btn = 6;
/*
    Initial default debounce delay
*/
const long debounceDelay = 50;

/* 
  initButtonsAndButtonInterrupts subroutine is called from Setup() function
  during the initialization of Speden Spelit. This function does the following:
  1) Initializes 4 button pins for the game = Arduino pins 2,3,4,5
  2) Initializes 1 button pin for starting the game = Aruino pin 6
*/

void initButtonsAndButtonInterrupts(void);

/*
    Enables ISR service in loop() function. Whenever any button state becomes LOW
    timestamp is made and button state is read. Then depending on last button state
    and reading state function updates button states and timestamps.
    
    Returns: button pin number
*/
int isButtonPressed(void);

#endif
