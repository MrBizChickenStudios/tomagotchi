#pragma once

#include <Arduino.h>

#define BTN_A 32
#define BTN_B 33
#define BTN_C 25

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
