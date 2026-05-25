#include <Arduino.h>
#include <TFT_eSPI.h>
#include <FS.h>
#include <LittleFS.h>
#include "DrawAssets.h"
#include "screen.h"
bool fsReady = false;

#define BG_FILE "/egg.raw"
#define BG_WIDTH  320
#define BG_HEIGHT 240

#define TRANSPARENT_COLOR 0xF81F

static uint16_t swap565(uint16_t c)
{
    return (c >> 8) | (c << 8);
}

static bool isTransparent(uint16_t raw)
{
    return raw == TRANSPARENT_COLOR || raw == 0x1FF8;
}

void setupDrawAssets()
{
    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);

    Serial.println("Mounting LittleFS...");

    fsReady = LittleFS.begin();

    if (!fsReady)
    {
        Serial.println("LittleFS mount failed.");
        return;
    }

    Serial.println("LittleFS mounted OK");
}

void drawRaw565(const char *filename, int16_t x, int16_t y, int16_t w, int16_t h)
{
    if (!fsReady) return;

    fs::File f = LittleFS.open(filename, "r");
    if (!f)
    {
        Serial.print("RAW file not found: ");
        Serial.println(filename);
        return;
    }

    static uint16_t lineBuffer[320];

    for (int row = 0; row < h; row++)
    {
        int bytesRead = f.read((uint8_t *)lineBuffer, w * 2);
        if (bytesRead != w * 2) break;

        tft.pushImage(x, y + row, w, 1, lineBuffer);
    }

    f.close();
}

void drawRaw565Transparent(const char *filename, int16_t x, int16_t y, int16_t w, int16_t h)
{
    if (!fsReady) return;

    fs::File f = LittleFS.open(filename, "r");
    if (!f) return;

    static uint16_t lineBuffer[320];

    for (int row = 0; row < h; row++)
    {
        int bytesRead = f.read((uint8_t *)lineBuffer, w * 2);
        if (bytesRead != w * 2) break;

        int drawY = y + row;
        if (drawY < 0 || drawY >= 240) continue;

        for (int col = 0; col < w; col++)
        {
            int drawX = x + col;
            if (drawX < 0 || drawX >= 320) continue;

            uint16_t raw = lineBuffer[col];
        

            if (!isTransparent(raw))
            {
                tft.drawPixel(drawX, drawY, swap565(raw));
            }
        }
    }

    f.close();
}

void drawBackground()
{
    drawRaw565(BG_FILE, 0, 0, BG_WIDTH, BG_HEIGHT);
}


void drawBackgroundRegion(int16_t x, int16_t y, int16_t w, int16_t h)
{
    if (!fsReady) return;

    fs::File f = LittleFS.open(BG_FILE, "r");
    if (!f) return;

    static uint16_t lineBuffer[320];

    for (int row = 0; row < h; row++)
    {
        int bgY = y + row;

        if (bgY < 0 || bgY >= BG_HEIGHT)
            continue;

        uint32_t offset = ((bgY * BG_WIDTH) + x) * 2;

        f.seek(offset);

        int bytesRead = f.read((uint8_t *)lineBuffer, w * 2);

        if (bytesRead != w * 2)
            break;

        tft.pushImage(x, bgY, w, 1, lineBuffer);
    }

    f.close();
}


void drawPortalAsset(const char *filename, int16_t x, int16_t y, int16_t w, int16_t h)
{


    fs::File f = LittleFS.open(filename, "r");

    drawRaw565Transparent(filename, x, y, w, h);


   
}

void drawJerryAsset(const char *filename, int16_t x, int16_t y, int16_t w, int16_t h)
{
    
    fs::File f = LittleFS.open(filename, "r");

    drawRaw565Transparent(filename, x, y, w, h);


   
}

void drawRaw565ToSprite(const char *filename, TFT_eSprite& spr,
                        int16_t x, int16_t y, int16_t w, int16_t h)
{
    if (!fsReady) return;

    fs::File f = LittleFS.open(filename, "r");
    if (!f) return;

    static uint16_t lineBuffer[320];

    for (int row = 0; row < h; row++)
    {
        int bytesRead = f.read((uint8_t *)lineBuffer, w * 2);
        if (bytesRead != w * 2) break;

        int drawY = y + row;
        if (drawY < 0 || drawY >= spr.height()) continue;

        for (int col = 0; col < w; col++)
        {
            int drawX = x + col;
            if (drawX < 0 || drawX >= spr.width()) continue;

            uint16_t raw = lineBuffer[col];

            if (!isTransparent(raw))
            {
                spr.drawPixel(drawX, drawY, swap565(raw));
            }
        }
    }

    f.close();
}