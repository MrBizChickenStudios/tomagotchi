#pragma once
#include <Arduino.h>
#include <TFT_eSPI.h>


#define SCREEN_W 320
#define SCREEN_H 240

extern TFT_eSPI tft;

void setupScreen();

void draw();
