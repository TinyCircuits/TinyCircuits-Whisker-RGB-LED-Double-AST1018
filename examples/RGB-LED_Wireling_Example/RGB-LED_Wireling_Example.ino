/*********************************************************************
 * This example shows how to program an RGB LED Wireling. The default 
 * program when uploaded will cycle every LED attached through the 
 * RGB colors at half brightness.
 * 
 * Written by: Laveréna Wienclaw for TinyCircuits
 * 
 * Initialized: 7/1/2018
 * Last Updated: 8/6/2019
 *********************************************************************/
 
#include <FastLED.h>

#define NUM_LEDS 1 // This is the number of RGB LEDs connected to the pin
#define LED_PIN A0 // Corresponds to Wireling Port 0 (A1 = Port 1, A2 = Port 2, A3 = Port 3)
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];
int brightness = 128; // Brightness is on a scale of 0-255, 128 is 50% brightness

const int powerPin = 4;  // For Wireling Adapter Power

void setup() {
  pinMode(powerPin, OUTPUT); // Wireling Power
  digitalWrite(powerPin, HIGH);

  // Initialize RGB LEDs attached to LED_PIN
  FastLED.addLeds<WS2812, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(brightness);
  pinMode(LED_PIN, OUTPUT);
}
void loop() {
  for(int x = 0; x < NUM_LEDS; x++) // cycle through all LEDs attached to LED_PIN
  {
    leds[x] = CRGB( 255, 0, 0); // RED
    FastLED.show();
    delay(500);
    leds[x] = CRGB(0, 255, 0); // GREEN
    FastLED.show();
    delay(500);
    leds[x] = CRGB(0, 0, 255); // BLUE
    FastLED.show();
    delay(500);
  }
}
