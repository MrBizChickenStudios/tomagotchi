#include <Arduino.h>
#include "screen.h"
#include "foodScreen.h"
#include "DrawAssets.h"
#include "Buttons.h"
#include "MoveJerryScreen.h"

unsigned long moveDelay = 0;

bool jerryScreen = true;
bool eatingScreen = false;

// hold timers
unsigned long aHoldStart = 0;
unsigned long bHoldStart = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);

  setupScreen();
  setupButtons();
  setupEatingScreen();

  randomSeed(analogRead(A0));

  setupDrawAssets();
  moveDelay = random(3000, 6000);
}

void loop() {

  updateButtons();

  // =========================
  // HOLD A FOR 3 SECONDS
  // -> EATING SCREEN
  // =========================
  if (currentButtons.a == LOW)
  {
    if (aHoldStart == 0)
    {
      aHoldStart = millis();
    }

    if (millis() - aHoldStart >= 3000)
    {
      eatingScreen = true;
      jerryScreen = false;
    }
  }
  else
  {
    aHoldStart = 0;
  }

  // =========================
  // HOLD B FOR 3 SECONDS
  // -> JERRY SCREEN
  // =========================
  if (currentButtons.b == LOW)
  {
    if (bHoldStart == 0)
    {
      bHoldStart = millis();
    }

    if (millis() - bHoldStart >= 3000)
    {
      jerryScreen = true;
      eatingScreen = false;
    }
  }
  else
  {
    bHoldStart = 0;
  }

  // =========================
  // ACTIVE SCREEN
  // =========================
  if (eatingScreen)
  {
    updateEatingScreen();
  }

  if (jerryScreen)
  {
    moveJerry(moveDelay);
  }
}