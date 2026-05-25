#include "foodScreen.h"

bool aLastState = HIGH;
bool bLastState = HIGH;




int hunger = 50;
int happiness = 50;
int selected = 0;

void drawBar(int x, int y, int w, int h, int value, uint16_t color)
{
    int fillW = map(value, 0, 100, 0, w);

    tft.drawRect(x, y, w, h, TFT_WHITE);
    tft.fillRect(x + 1, y + 1, fillW - 2, h - 2, color);
}

void drawFoodUI()
{
    tft.fillScreen(TFT_BLACK);

    tft.setTextDatum(MC_DATUM);
    tft.setTextSize(2);
    tft.setTextColor(TFT_WHITE);

    tft.drawString("FOOD MENU", 160, 20);

    // === BARS ===
    tft.setTextSize(1);
    tft.drawString("Hunger", 70, 60);
    drawBar(30, 75, 120, 12, hunger, TFT_GREEN);

    tft.drawString("Happiness", 230, 60);
    drawBar(180, 75, 120, 12, happiness, TFT_YELLOW);

    // === MEAL BOX ===
    if (selected == 0)
        tft.fillRect(30, 110, 260, 60, TFT_GREEN);
    else
        tft.drawRect(30, 110, 260, 60, TFT_WHITE);

    tft.setTextSize(2);
    tft.setTextColor(TFT_WHITE);
    tft.drawString("MEAL (+25)", 160, 140);

    // === SNACK BOX ===
    if (selected == 1)
        tft.fillRect(30, 180, 260, 60, TFT_GREEN);
    else
        tft.drawRect(30, 180, 260, 60, TFT_WHITE);

    tft.drawString("SNACK (+15)", 160, 210);
}

void handleFoodInput(){   
    bool aCurrentState = digitalRead(BTN_A);
    bool bCurrentState = digitalRead(BTN_B);



    

    if (aLastState == HIGH & aCurrentState == LOW)
    {
        selected = 0;

        hunger += 25;
        happiness += 25;
        drawFoodUI();
        Serial.print(" a pressed");
        
        delay(200);

    }
    aLastState = aCurrentState;
    
    if (bLastState == HIGH & bCurrentState == LOW)
    {
        selected = 1;

        hunger += 15;
        happiness += 15;
        drawFoodUI();
        Serial.print(" b pressed");
       
        delay(200);


        
    }
    bLastState = bCurrentState;

    // clamp values
    hunger = constrain(hunger, 0, 100);
    happiness = constrain(happiness, 0, 100);

    // drawFoodUI();

    delay(200); // debounce
}

void setupFoodUI()
{
    pinMode(BTN_A, INPUT_PULLUP);
    pinMode(BTN_B, INPUT_PULLUP);

    tft.init();
    tft.setRotation(1);

    
    drawFoodUI();
}