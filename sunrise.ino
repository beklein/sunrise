#include <FastLED.h>

// change your pin, color order, ... depending on your hardware setup
#define LED_PIN     3
#define COLOR_ORDER GRB
#define CHIPSET     WS2812B
#define NUM_LEDS    180
#define MAX_BRIGTHNESS 255


CRGB leds[NUM_LEDS];
CRGBPalette16 myPal;

void setup() {
  // delay against flickering
  delay(1000);

  // define your LEDs above
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
   
  // define your color palette or use an existing one
  myPal = CRGBPalette16( CRGB::Red, CRGB::Orange, CRGB::Yellow, CRGB::White);
}

void loop() {
  // that's all
  sunrise();
}

// increase brigthness of each LED with a gradient color palette one after the other
void sunrise() {
  // i = LED number loop
  for(int i = 0; i < NUM_LEDS; i++){
    // j = LED brigthness loop
    for(int j = 0; j < MAX_BRIGTHNESS; j++){
      leds[i] = ColorFromPalette(myPal, i, j, LINEARBLEND);
      // brigthness delay in ms
      delay(2);
      FastLED.show();
    }
    // LED delay in ms
    delay(10);    
  }
}

