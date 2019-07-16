//**********************************************************
// Test Code for RGB LED TinyBoards!
//
//
//**********************************************************

#include <Wire.h> 
#include "Adafruit_NeoPixel.h"

#define PIN            A2
#define NUMPIXELS      32

const int powerPin = 4;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

void setup() {
  Wire.begin(); 
  pinMode(powerPin, OUTPUT);
  digitalWrite(powerPin, HIGH);

  selectPort(2); 
  pixels.begin(); // This initializes the NeoPixel library.
  pixels.show();
}

void loop() {
  for (int i = 0; i <= NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 150, 0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    SerialUSB.println("Hello");
  }

}

void selectPort(int port) {
  Wire.beginTransmission(0x70);
  Wire.write(0x04 + port);
  Wire.endTransmission();
}
