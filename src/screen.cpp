#include "screen.h"
#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#define TFT_CS   D8
#define TFT_DC   D3
#define TFT_RST  D4

Adafruit_ILI9341 tft(TFT_CS, TFT_DC, TFT_RST);

void setupScreen() {
  tft.begin();
  tft.setRotation(1);

  
}

void draw() {
    tft.fillScreen(ILI9341_BLACK);

    tft.setTextColor(ILI9341_WHITE);
    tft.setTextSize(2);
    tft.setCursor(20, 50);
    tft.println("HELLO WORLD");
}