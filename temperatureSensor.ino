#include <Arduino.h>
#include <elapsedMillis.h>

const int temperaturePin = A0;  // LM35 sensor connected to Analog pin A0
const int ledPin = 13;  // Onboard LED pin

int temperature;
int blinkInterval = 250;

elapsedMillis ledTimer;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void toggleLED() {
  digitalWrite(ledPin, !digitalRead(ledPin));  // Toggle LED state
}

void loop() {
  temperature = analogRead(temperaturePin);
  temperature = (temperature * 500) / 1023;  // Convert analog reading to temperature in Celsius

  if (temperature < 30) {
    if (ledTimer >= blinkInterval) {
      toggleLED();
      ledTimer = 0;
    }
  } else {
    blinkInterval = 500;  // Set blink interval for temperature above 30 degrees
    if (ledTimer >= blinkInterval) {
      toggleLED();
      ledTimer = 0;
    }
  }
}
