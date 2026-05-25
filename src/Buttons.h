#pragma once

#include <Arduino.h>

#define BTN_A D1
#define BTN_B D2
#define BTN_C D6


extern bool aPressed;
extern bool bPressed;
extern bool cPressed;
struct ButtonStates
{
    bool a;
    bool b;
    bool c;
};

extern ButtonStates currentButtons;
extern ButtonStates lastButtons;

void setupButtons();

void updateButtons();

bool buttonAPressed();
bool buttonBPressed();
bool buttonCPressed();
