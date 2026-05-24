#pragma once
#include <Arduino.h>
#include <Adafruit_ST7789.h>
#include "test.h"



extern Adafruit_ST7789 tft;


void setupScreen();

void draw();

void drawText(String text, int textX, int textY);

void drawText(String text, int textX, int textY, uint16_t color );