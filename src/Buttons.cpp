#include "Buttons.h"

ButtonStates currentButtons = {HIGH, HIGH, HIGH};
ButtonStates lastButtons    = {HIGH, HIGH, HIGH};

void setupButtons()
{
    pinMode(BTN_A, INPUT_PULLUP);
    pinMode(BTN_B, INPUT_PULLUP);
    pinMode(BTN_C, INPUT_PULLUP);
}

void updateButtons()
{
    // save old states
    lastButtons = currentButtons;

    // read new states
    currentButtons.a = digitalRead(BTN_A);
    currentButtons.b = digitalRead(BTN_B);
    currentButtons.c = digitalRead(BTN_C);
}

bool buttonAPressed()
{
    return lastButtons.a == HIGH &&
           currentButtons.a == LOW;
}

bool buttonBPressed()
{
    return lastButtons.b == HIGH &&
           currentButtons.b == LOW;
}

bool buttonCPressed()
{
    return lastButtons.c == HIGH &&
           currentButtons.c == LOW;
}
