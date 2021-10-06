/////////////////////////////////////////////////////////
//
// Läheisyys testi
//
// Author     : Jani Hirvinen, jani@jdronics.fi
// Version    : v1.0 6-10-2021
//
/////////////////////////////////////////////////////////
// Harrastamisen Malli Demo
//
// Testi sketchi jolla testataan erityyppisiä läheisyys
// antureita
//
///////////////////////////////////////////////////////////
//
//  Kytkentä:
// - GND    - GND
// - VCC    - 5V
// - Signal - D10 pin
//
///////////////////////////////////////////////////////////


/////////////////////
// INCLUDES


/////////////////////
// Defines and declarations

#define LEDPIN 13
#define ANTURI 10

/////////////////////
// Globaalit muuttujat


void setup() {
  // put your setup code here, to run once:

  pinMode(ANTURI, INPUT_PULLUP);
  pinMode(LEDPIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LEDPIN, digitalRead(ANTURI));

}
