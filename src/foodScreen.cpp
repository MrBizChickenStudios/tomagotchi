#include "foodScreen.h"
#include "screen.h"
#include "Buttons.h"


int hunger = 50;
int happiness = 50;
int selectedOption = 0;

const int GAP = SCREEN_H / 24;
const int BOX_W = SCREEN_W * 0.9;
const int BOX_H = SCREEN_H / 4;
const int BOX_X = SCREEN_W / 2 - BOX_W / 2;
const int SNACK_Y = SCREEN_H - BOX_H;
const int MEAL_Y = SNACK_Y - GAP;
const int BAR_W = BOX_W / 2 - GAP * 2;
const int BAR_H = GAP * 1.5;
const int BAR_Y = MEAL_Y - GAP * 2;
const int HUNGER_BAR_X = BOX_X;
const int HAPPINES_BAR_X = SCREEN_W / 2 + GAP * 2;


void drawBar(int x, int y, int w, int h, int value, uint16_t color)
{
    int fillW = map(value, 0, 100, 0, w);
    tft.drawRect(x, y, w, h, TFT_WHITE);
    tft.fillRect(x + 1, y + 1, fillW - 2, h - 2, color);
}


void drawEatingScreen()
{
    tft.fillScreen(TFT_BLACK);
    tft.setTextDatum(MC_DATUM);
    tft.setTextSize(2);
    tft.setTextColor(TFT_WHITE);

    String s = "FOOD MENU";
    int x = SCREEN_W / 2  - tft.textWidth(s) / 2;
    int y = tft.fontHeight() * 2;
    tft.drawString(s, x, y);

    // === BARS ===
    tft.setTextSize(1);
    s = "Hunger";
    x = HUNGER_BAR_X +  BAR_W / 2 - tft.textWidth(s) / 2;
    y = BAR_Y - GAP;
    tft.drawString(s, x, y);

    s = "Happiness";
    x = HAPPINES_BAR_X +  BAR_W / 2 - tft.textWidth(s) / 2;
    y = BAR_Y - GAP;
    tft.drawString(s, x, y);

    drawBar(BOX_X, BAR_Y, BAR_W, BAR_H, hunger, TFT_GREEN);
    drawBar(180, BAR_Y, BAR_W, BAR_H, happiness, TFT_YELLOW);

    // === MEAL BOX ===
    if (selectedOption == 0)
        tft.fillRect(BOX_X, MEAL_Y, BOX_W, BOX_H, TFT_GREEN);
    else
        tft.drawRect(BOX_X, MEAL_Y, BOX_W, BOX_H, TFT_WHITE);

    tft.setTextSize(2);
    tft.setTextColor(TFT_WHITE);

    // === SNACK BOX ===
    if (selectedOption == 1)
        tft.fillRect(BOX_X, SNACK_Y, BOX_W, BOX_H, TFT_GREEN);
    else
        tft.drawRect(BOX_X, SNACK_Y, BOX_W, BOX_H, TFT_WHITE);

    s = "MEAL (+25)";
    x = BOX_X + BOX_W / 2 - tft.textWidth(s) / 2;
    y = MEAL_Y / 2 - tft.fontHeight();
    tft.drawString(s, x, y);

    s = "SNACK (+15)";
    x = BOX_X + BOX_W / 2 - tft.textWidth(s) / 2;
    y = SNACK_Y / 2 - tft.fontHeight();
    tft.drawString(s, x, y);
}


void updateEatingScreen(){

    updateButtons();
    if (buttonAPressed())
    {
        selectedOption = 0;
        hunger += 25;
        happiness += 25;
        drawEatingScreen();
        Serial.print(" a pressed");
        delay(200);

    }

    if (buttonAPressed())
    {
        selectedOption = 1;
        hunger += 15;
        happiness += 15;
        drawEatingScreen();
        Serial.print(" b pressed");
        delay(200);
    }

    // clamp values
    hunger = constrain(hunger, 0, 100);
    happiness = constrain(happiness, 0, 100);


}

void setupEatingScreen()
{
    drawEatingScreen();
}



void setHunger(int h){
  hunger += h;
}


void setHappiness(int h){
  happiness += h;
}


int getHunger(){
  return hunger;
}


int gethappiness(){
  return happiness;
}
