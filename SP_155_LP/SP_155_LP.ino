#include <avr/sleep.h>

#define LASER_PIN 4
#define OVERRIDE_PIN 2

bool ovr = false;

void setup() {
  pinMode(LASER_PIN, OUTPUT);
  pinMode(OVERRIDE_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(OVERRIDE_PIN), set_ovr, CHANGE);
}

// the loop function runs over and over again forever
void loop() {
  delay(3000);
  sleepytime();
}

void set_ovr(){
  sleep_disable();
  ovr = digitalRead(OVERRIDE_PIN);
  digitalWrite(LASER_PIN, !ovr);
}

void sleepytime(){
  sleep_enable();
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  digitalWrite(LED_BUILTIN,LOW);
  delay(200);
  sleep_cpu();
}
