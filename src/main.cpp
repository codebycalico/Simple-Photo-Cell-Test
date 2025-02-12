// Program to test the photo cell for possible use
// for the HOW FAST exhibit in Natural Sciences
// at OMSI.
// Created by Calico Randall
// February 12, 2025

#include <Arduino.h>

/* Photocell simple testing sketch. 
 
Connect one end of the photocell to 5V, the other end to Analog 0.
Then connect one end of a 10K resistor from Analog 0 to ground 
Connect LED from pin 11 through a resistor to ground 
For more information see http://learn.adafruit.com/photocells */

// The photo cell and 10k pulldown resistor are connected to pin 0
#define PHOTOCELL_PIN 19
// LED_PIN for the red LED on the board
#define LED_PIN 13
// The raw analog reading from the sensor divider
int photocellReading;

void setup() {
  Serial.begin(9600);   
}
 
void loop() {
  photocellReading = analogRead(PHOTOCELL_PIN); 
 
  Serial.print("Analog reading = ");
  Serial.println(photocellReading);
 
  // // LED gets brighter the darker it is at the sensor
  // // that means we have to -invert- the reading from 0-1023 back to 1023-0
  // photocellReading = 1023 - photocellReading;
  // //now we have to map 0-1023 to 0-255 since thats the range analogWrite uses
  // LEDbrightness = map(photocellReading, 0, 1023, 0, 255);
  digitalWrite(LED_PIN, HIGH);
 
  delay(100);
}