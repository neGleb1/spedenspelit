#ifndef SPEDENSPELIT_H
#define SPEDENSPELIT_H
#include <arduino.h>


/*
    Made by Danil Akhmetshin and Simo Sainio.
*/


/* The highest score among all players */
volatile uint8_t highScore = 0;

/* Game status flag */
volatile bool gameIsActive = false;

/* Generated numbers and player's input data */
volatile uint8_t generatedNumbers[100];
volatile uint8_t playerNumbers[100];

/* Separated indexes for generated numbers and player's data */
volatile uint8_t currentScore = 0;
volatile uint8_t currentNumber = 0;

/* Sound pin */
const int buzzer = 14;


/*
  initializeTimer() subroutine intializes Arduino Timer1 module to
  give interrupts at rate 1Hz.
*/
void initializeTimer(void);


/*
  initializeGame() subroutine changes game status to active.
*/
void initializeGame(void);


/*
  checkGame() subroutine compares generated numbers
  and player input after each player button press.
  
  If the latest player button press is wrong, the game stops
  and if the latest press was right, player's score is incremented
  by 1.

  Also game is stopped after 100 correct input.
  
  Parameters:
  uint8_t lastButtonPress of the player 0 or 1 or 2 or 3
*/
void checkGame(uint8_t lastButtonPress);


/*
  startTheGame() subroutine clears leds,
  set indexes for generated numbers and player's data to 0,
  calls InitializeGame() function
  and enables Timer1 interrupts to start the Game.
*/
void startTheGame(void);


/*
  stopTheGame() subroutine changes game status to active,
  clears leds, sets highscore and display it.
*/
void stopTheGame(void);


/*
  initializeSound() subroutine intializes sound pin.
*/
//void initializeSound(void);

#endif
