#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

#define TFT_CS   D8
#define TFT_DC   D3
#define TFT_RST  D4

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void setupScreen() {
  SPI.setFrequency(40000000);

  tft.init(240, 320);   // IMPORTANT for ST7789
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);


}

void draw(){


  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  
}

void drawText(String text, int textX, int textY){
    tft.setCursor(textX, textY);
    tft.fillRect(textX, textY, 50, 50, ST77XX_BLACK);
    tft.println(text);
    

}

void drawText(String text, int textX, int textY, uint16_t color ){
    tft.setCursor(textX, textY);
    tft.fillRect(textX, textY, 50, 50, color);
    tft.println(text);
    

}