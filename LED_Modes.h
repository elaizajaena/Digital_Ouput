void setAllLEDs(uint8_t state) {
  for (int i = 0; i < NUM_PINS; i++) {
    digitalWrite(LEDS[i], state);
  }
}

// Mode 1: All LEDs blink together 3 times
void blink() {
  for (int i = 0; i < 3; i++) {
    setAllLEDs(HIGH);
    delay(DELAY_TIME);
    setAllLEDs(LOW);
    delay(DELAY_TIME);
  }
}

// Mode 2: Alternates between first 3 LEDs and last 3 LEDs
void alt() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < NUM_PINS; j++) {
      digitalWrite(LEDS[j], j < 3 ? HIGH : LOW);
    }
    delay(DELAY_TIME);

    for (int j = 0; j < NUM_PINS; j++) {
      digitalWrite(LEDS[j], j < 3 ? LOW : HIGH);
    }
    delay(DELAY_TIME);
  }
  setAllLEDs(LOW);
}

// Mode 3: Knight Rider / Chaser effect back and forth
void run() {
  for (int repeat = 0; repeat < 3; repeat++) {
    // Forward sequence (LED 1 to 6)
    for (int i = 0; i < NUM_PINS; i++) {
      digitalWrite(LEDS[i], HIGH);
      delay(DELAY_TIME);
      digitalWrite(LEDS[i], LOW);
    }
    
    // Reverse sequence (LED 5 down to 1)
    for (int i = NUM_PINS - 2; i >= 0; i--) {
      digitalWrite(LEDS[i], HIGH);
      delay(DELAY_TIME);
      digitalWrite(LEDS[i], LOW);
    }
    delay(DELAY_TIME);
  }
}