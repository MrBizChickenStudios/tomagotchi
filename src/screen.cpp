#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>

#define TFT_CS   D8
#define TFT_DC   D3
#define TFT_RST  D4

TFT_eSPI tft = TFT_eSPI();

void setupScreen() {
  tft.init();              // must be first
  tft.setRotation(1);

  tft.fillScreen(TFT_RED); // 👈 PUT IT HERE (test)

  delay(500);
  tft.fillScreen(TFT_GREEN);
  delay(500);
  tft.fillScreen(TFT_BLUE);
  delay(500);

  tft.fillScreen(TFT_BLACK); // final screen state
}



