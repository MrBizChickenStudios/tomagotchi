#pragma once
#include <TFT_eSPI.h>
#include <Arduino.h>

void setupDrawAssets();
void drawBackground();
void drawPortalAsset(const char *filename, int16_t x, int16_t y, int16_t w, int16_t h);
void drawJerryAsset(const char *filename, int16_t x, int16_t y, int16_t w, int16_t h);
void drawRaw565ToSprite(const char *filename, TFT_eSprite& spr, int16_t x, int16_t y, int16_t w, int16_t h);
void drawBackgroundRegion(int16_t x, int16_t y, int16_t w, int16_t h);