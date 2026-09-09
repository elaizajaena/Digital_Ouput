void setAllLEDs(uint8_t state) {
  for (int i = 0; i < NUM_PINS; i++) {
    digitalWrite(LEDS[i], state);
  }
}

void off() {
  setAllLEDs(LOW);
}

void blink() {
  setAllLEDs(HIGH);
  delay(DELAY_TIME);
  setAllLEDs(LOW);
  delay(DELAY_TIME);
}

void alt() {
  for (int j = 0; j < NUM_PINS; j++) {
    digitalWrite(LEDS[j], j < 3 ? HIGH : LOW);
  }
  delay(DELAY_TIME);

  for (int j = 0; j < NUM_PINS; j++) {
    digitalWrite(LEDS[j], j < 3 ? LOW : HIGH);
  }
  delay(DELAY_TIME);
  setAllLEDs(LOW); 
}

void run() {
  for (int i = 0; i < NUM_PINS; i++) {
    digitalWrite(LEDS[i], HIGH);
    delay(DELAY_TIME);
    digitalWrite(LEDS[i], LOW);
  }

  for (int i = NUM_PINS - 2; i > 0; i--) {
    digitalWrite(LEDS[i], HIGH);
    delay(DELAY_TIME);
    digitalWrite(LEDS[i], LOW);
  }
  setAllLEDs(LOW);
}
