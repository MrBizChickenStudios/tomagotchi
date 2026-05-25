#include <Arduino.h>
#include "DrawAssets.h"
#include"screen.h"

int x = 100;
int oldX = 100;

unsigned long lastMove = 0;
unsigned long nextMoveDelay = 0;



void moveJerry(int nextMoveDelay){
     if (millis() - lastMove > nextMoveDelay)
    {
        lastMove = millis();

        oldX = x;

        x = random(0, 230);

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