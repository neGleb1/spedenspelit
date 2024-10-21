#include "buttons_final.h"


/*
    Made by Danil Akhmetshin.
*/


/*
    Buttons last push timestamps
*/
unsigned long lastDebounceTimes[] = {0,0,0,0};
/*
    Buttons last states
*/
int lastButtonStates[] = {HIGH, HIGH, HIGH, HIGH};


void initButtonsAndButtonInterrupts(void)
{
  /*
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  */
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);
  pinMode(btn4, INPUT_PULLUP);
  pinMode(start_game_btn, INPUT_PULLUP);
}

int isButtonPressed() {
  for (int i = 0; i < 4; i++) {
    unsigned long now = millis();
   
    int reading = digitalRead(buttons[i]);
 
    if (reading == LOW && lastButtonStates[i] == HIGH) {
      if ((now - lastDebounceTimes[i]) > debounceDelay) {
        lastButtonStates[i] = LOW;
        return buttons[i];
      }
    } else {
      lastButtonStates[i] = reading;
      lastDebounceTimes[i] = now;
    }
  }
  return -1;
}
