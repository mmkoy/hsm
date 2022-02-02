/////////////////////////////////////////////////////////
//
// NeoPixel Rover lights
//
// Author     : Jani Hirvinen, jani@jdronics.fi
// Version    : v1.0 02-02-2022
//
/////////////////////////////////////////////////////////
// Harrastamisen Malli Esimerkki
//
// NeoPixel ledi testi ohjelma jolla ohjataan Roverin valoja
//
///////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////


#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif


#define PIN        6 // IO Pinna missä NeoPixelien data linja on 


#define NUMPIXELS 5 // Kuinka monta lediä meillä on 

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define LPIN 8
#define RPIN 9
#define FPIN 10


unsigned long prevMil = 0;
unsigned long curMil = 0;
boolean ledState;

int interval = 500;

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif

  pinMode(LPIN, INPUT_PULLUP);
  pinMode(RPIN, INPUT_PULLUP);
  pinMode(FPIN, INPUT_PULLUP);

  pixels.begin();
}

void loop() {
  pixels.clear();             // Sammutetaan kaikki ledit
  pixels.setBrightness(25);   // Määritellään

  curMil = millis();
  if (curMil - prevMil >= interval) {
    prevMil = curMil;
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
  }


  if (!digitalRead(LPIN) && ledState) {
    pixels.setPixelColor(0, pixels.Color(255, 255, 0));
  } else {
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
  }

  if (!digitalRead(RPIN) && ledState) {
    pixels.setPixelColor(4, pixels.Color(255, 255, 0));
  } else {
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));
  }

  if (!digitalRead(FPIN)) {
    pixels.setPixelColor(1, pixels.Color(255, 255, 255));
    pixels.setPixelColor(2, pixels.Color(255, 255, 255));
    pixels.setPixelColor(3, pixels.Color(255, 255, 255));
  } else {
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));
  }
  pixels.show();   
}
