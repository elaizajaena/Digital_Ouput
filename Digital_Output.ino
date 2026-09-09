/*======================================================
                     DIGITAL OUTPUT
========================================================
Description:
This program blinks an LED connected to GPIO32 with a
time interval. It uses standard output configurations 
and precise delay timing to cycle through three 
distinct lighting animation patterns continuously in a 
loop.

Designer Engineer:
Ebio, Ann Clarise
Jaena, Elaiza B.

Date:
Sept. 02, 2026
======================================================*/

// ESP32 GPIO Pins
const int LEDS[] = {32, 33, 25, 0, 2, 15};
const int NUM_PINS = sizeof(LEDS) / sizeof(LEDS[0]);
const int DELAY_TIME = 500;

#include "LED_Modes.h"

void setup() {
  for (int i = 0; i < NUM_PINS; i++) {
    pinMode(LEDS[i], OUTPUT);
  }
}

void loop() {
  blink();
  alt();
  run();

  delay(500); // Wait 1 second before restarting loop
}



