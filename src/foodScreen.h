#pragma once

#include <Arduino.h>
#include <TFT_eSPI.h>



extern TFT_eSPI tft;

// stats
extern int hunger;
extern int happiness;
extern int selected;

void setupFoodUI();
void drawFoodUI();
void handleFoodInput();