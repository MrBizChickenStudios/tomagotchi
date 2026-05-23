#pragma once
#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>



extern Adafruit_ILI9341 tft;

void setupScreen();

void draw();