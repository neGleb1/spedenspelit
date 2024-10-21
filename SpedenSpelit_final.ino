#include "display_final.h"
#include "buttons_final.h"
#include "leds_final.h"
#include "SpedenSpelit_final.h"


/*
    Made by Danil Akhmetshin and Simo Sainio.
*/


/*
    All modules are initialized here.
*/
void setup()
{
  Serial.begin(9600);
  initButtonsAndButtonInterrupts();
  initializeLeds();
  initializeDisplay();
}


/*
    This loop function constantly checks if
	player has pushed a button.
*/
void loop()
{
  if (!gameIsActive) {
       if (digitalRead(start_game_btn) == LOW) {
        startTheGame();
        Serial.println("start");
       }
  }
  if (gameIsActive) {
    int button = isButtonPressed();
    if (button >= 2 && button < 6){
      checkGame(button);
      Serial.println(button);
    }
  }
}


/*
    Timer service generates a random number that is used to
	set certain led.

	Each timer interrupt increments "played" numbers,
	and after each 10 numbers interrupt
	frequency is incremented by 10%.
	
	Each generated random number is stored for later
	comparision against player push button presses.
*/
ISR(TIMER1_COMPA_vect)
{
    if (gameIsActive) {
        clearAllLeds();
        if(currentNumber < 100){
            generatedNumbers[currentNumber] = rand() % 4;
            while (generatedNumbers[currentNumber] == generatedNumbers[currentNumber-1]){
                generatedNumbers[currentNumber] = rand() % 4;
            }
            setLed(generatedNumbers[currentNumber]);
            currentNumber++;
            if ((currentNumber % 10 == 0) && (currentNumber != 0)) {
                OCR1A *= 0.9;
            }
        }
    }
}

void initializeTimer()
{
    TCCR1A = 0;
    TCCR1B = 0;
    OCR1A = 62500;
    TCCR1B = (1<<WGM12) | (1<<CS12); 
    TIMSK1 = (1<<OCIE1A);
}

void checkGame(uint8_t lastButtonPress)
{
	playerNumbers[currentScore] = lastButtonPress-2;
	if ((playerNumbers[currentScore] == generatedNumbers[currentScore]) & (currentScore < 100)){
	    currentScore++;
	    showResult(currentScore);
      	tone(buzzer, 1100, 50);
	} else {
	    stopTheGame();
	}
}


void initializeGame()
{
	gameIsActive = true;
}

void startTheGame()
{
   currentScore = 0;
   currentNumber = 0;
   clearAllLeds();
   initializeGame();
   initializeTimer();
   showResult(currentScore);
}

void stopTheGame()
{
    highScore = (currentScore > highScore) ? currentScore : highScore;
    gameIsActive = false;
    clearAllLeds();
    tone(buzzer, 200, 1000);
    showResult(highScore);
}


void initializeSound()
{
  pinMode(buzzer, OUTPUT);
}


