//**********************************************************
// Test Code for RGB LED TinyBoards!
//
//
//**********************************************************

#include <Wire.h> 
#include "Adafruit_NeoPixel.h"

#define PIN            A0 // corresponds to Port 0 (A1 = Port1, A2 = Port 2, A3 = Port 3)
#define NUMPIXELS      1 // this is the number of RGB LEDs connected to the pin

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

void setup() {
  Wire.begin(); 

  pixels.begin(); // This initializes the NeoPixel library.
  pixels.show();
}

void loop() {
  for (int i = 0; i <= NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 150, 0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
}
