#include <FastLED.h>

#define LED_PIN     0
#define NUM_LEDS    12
#define BRIGHTNESS  255
#define LED_TYPE    NEOPIXEL
#define COLOR_ORDER RGB
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100

// This example shows several ways to set up and use 'palettes' of colors
// with FastLED.
//
// These compact palettes provide an easy way to re-colorize your
// animation on the fly, quickly, easily, and with low overhead.
//
// USING palettes is MUCH simpler in practice than in theory, so first just
// run this sketch, and watch the pretty lights as you then read through
// the code.  Although this sketch has eight (or more) different color schemes,
// the entire sketch compiles down to about 6.5K on AVR.
//
// FastLED provides a few pre-configured color palettes, and makes it
// extremely easy to make up your own color schemes with palettes.
//
// Some notes on the more abstract 'theory and practice' of
// FastLED compact palettes are at the bottom of this file.

CRGB light = CRGB(200, 100, 20);
int oldState = 1;
int cylonPos = 0;

void setLEDs(CRGB color) {
    for (int i=0; i<NUM_LEDS; i++) {
        leds[i] = color;
    }
}

void setup() {
    FastLED.addLeds<LED_TYPE, LED_PIN>(leds, NUM_LEDS);
    FastLED.setBrightness(  BRIGHTNESS );

    pinMode(1, INPUT);
    pinMode(2, INPUT);
    pinMode(5, INPUT);

    setLEDs(light);
    FastLED.show();
    delay(100);
    setLEDs(CRGB::Black);
    FastLED.show();
}

void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(250); } }

void cylon() {
  static uint8_t hue = 0;
  // First slide the led in one direction
  for(int i = 0; i < NUM_LEDS; i++) {
    // Set the i'th led to red 
    leds[i] = CHSV(hue++, 255, 255);
    // Show the leds
    FastLED.show(); 
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    fadeall();
    // Wait a little bit before we loop around and do it again
    delay(10);
  }

  // Now go in the other direction.  
  for(int i = (NUM_LEDS)-1; i >= 0; i--) {
    // Set the i'th led to red 
    leds[i] = CHSV(hue++, 255, 255);
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    fadeall();
    // Wait a little bit before we loop around and do it again
    delay(10);
  }
}

void loop()
{
    CRGB color = CRGB::Black;

    int pin1 = digitalRead(1);
//    int pin2 = digitalRead(2);
//    int pin3 = digitalRead(5);

    if (oldState != pin1) {
        oldState = pin1;
        color = light;
        delay(40);
/*    } else if (pin2 == HIGH) {
        color = CRGB::Red;
    } else if (pin3 == HIGH) {
        color = CRGB::Blue;
    } else if (pin2 == HIGH && pin3 == HIGH) {
        cylon();*/
    } else {
      color = CRGB::Black;
    }
    
    setLEDs(color);
 
    FastLED.show();
}
