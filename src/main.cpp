#include <Arduino.h>
#include "screen.h"
#include "foodScreen.h"
#include "DrawAssets.h"
#include "Buttons.h"
#include "MoveJerryScreen.h"

unsigned long moveDelay = 0;

bool jerryScreen = false;
bool eatingScreen = false;

unsigned long aHoldStart = 0;
unsigned long bHoldStart = 0;

unsigned long eggStartTime = 0;
bool introFinished = false;

void setup() {
  Serial.begin(115200);
  delay(1000);

  setupScreen();
  setupButtons();

  randomSeed(analogRead(A0));

  setupDrawAssets();

  // draw egg.raw
  tft.fillScreen(TFT_BLACK);

  drawPortalAsset("/egg.raw", 50, 100, 180, 180);


  eggStartTime = millis();

  moveDelay = random(3000, 6000);
}

void loop() {

  // ===== SHOW EGG FOR 20 SECONDS =====
  if (!introFinished)
  {
    if (millis() - eggStartTime >= 20000)
    {
      introFinished = true;

      jerryScreen = true;
      eatingScreen = false;

      tft.fillScreen(TFT_BLACK);
    }

    return;
  }

  updateButtons();

  // ===== HOLD A FOR FOOD SCREEN =====
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

      drawEatingScreen();

      aHoldStart = 0;
    }
  }
  else
  {
    aHoldStart = 0;
  }

  // ===== HOLD B FOR JERRY SCREEN =====
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

      tft.fillScreen(TFT_BLACK);

      bHoldStart = 0;
    }
  }
  else
  {
    bHoldStart = 0;
  }

  // ===== ACTIVE SCREEN =====
  if (eatingScreen)
  {
    updateEatingScreen();
  }

  if (jerryScreen)
  {
    moveJerry(moveDelay);
  }
}