#include <Arduino.h>
#include "screen.h"



int x = 0;

void setup() {
  setupScreen();
  
}

void loop() {
  String s = "my number is" + String(x) + " hello ";
  drawText(s, 20, 20, ST77XX_RED);

  drawText(String(x), 50 , 50);
  delay(1000);
  x ++;
}

