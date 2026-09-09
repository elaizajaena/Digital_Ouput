/*======================================================
                     DIGITAL OUTPUT
========================================================
Description:
This program blinks an LED connected to GPIO32 with a
time interval. It uses standard output configurations 
and precise delay timing to cycle through three 
distinct lighting animation patterns control by a
switch.

Designer Engineer:
Ebio, Ann Clarise
Jaena, Elaiza B.

Date:
Sept. 09, 2026
======================================================*/
const int SW1 = 34;
const int SW2 = 35;

const int LEDS[] = {32, 33, 25, 0, 2, 15};
const int NUM_PINS = sizeof(LEDS) / sizeof(LEDS[0]);
const int DELAY_TIME = 200;

int SW1_state = 0;
int SW2_state = 0;

#include "LED_Modes.h"

void setup() {
  for (int i = 0; i < NUM_PINS; i++) {
    pinMode(LEDS[i], OUTPUT);
  }

  pinMode(SW1, INPUT_PULLDOWN);
  pinMode(SW2, INPUT_PULLDOWN);
}

void loop() {
  SW1_state = digitalRead(SW1);
  SW2_state = digitalRead(SW2);

  off();

  if (SW1_state == 0 && SW2_state == 0) {
    off();
  } else if (SW1_state == 0 && SW2_state == 1) {
    blink();
  } else if (SW1_state == 1 && SW2_state == 0) {
    alt();
  } else if (SW1_state == 1 && SW2_state == 1) {
    run();
  }
}

Led_Modes.h



