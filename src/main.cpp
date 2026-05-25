#include <Arduino.h>
#include "screen.h"
#include "DrawAssets.h"

int x = 100;
int oldX = 100;

unsigned long lastMove = 0;
unsigned long nextMoveDelay = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);

  randomSeed(analogRead(A0));

  setupScreen();
  setupDrawAssets();

  nextMoveDelay = random(3000, 6000);
}

void loop() {

  if (millis() - lastMove > nextMoveDelay)
  {
    lastMove = millis();

    oldX = x;

    // new random position
    x = random(0, 230);

    // pick sprite based on direction
    if (x < oldX)
    {
      tft.fillScreen(TFT_BLACK);
      drawJerryAsset("/jerryleft.raw", x, 50, 180, 180);
    }
    else
    {
      tft.fillScreen(TFT_BLACK);
      drawJerryAsset("/jerry.raw", x, 50, 180, 180);
    }

    nextMoveDelay = random(3000, 6000);
  }
}