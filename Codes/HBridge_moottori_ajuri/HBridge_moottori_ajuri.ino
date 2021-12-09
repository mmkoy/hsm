
/////////////////////////////////////////////////////////
//
// H-Silta moottorin ohjaus
//
// Author     : Jani Hirvinen, jani@jdronics.fi
// Version    : v1.0 08-12-2021
//
/////////////////////////////////////////////////////////
// Harrastamisen Malli Esimerkki
//
// Kuinka kytketaan ja ohjataan H-Silta moottori ajuria
//
///////////////////////////////////////////////////////////
//
//  Kytkentä:
//
///////////////////////////////////////////////////////////


/////////////////////
// INCLUDES


/////////////////////
// Defines and declarations

#define AI1 6
#define BI1 7
#define PWMA 9


/////////////////////
// Globaalit muuttujat


//////////////////////
// SETUP(), Määritellään alku parametrit
// ja alustetaan objektit, portit jne

void setup() {

  pinMode(AI1, OUTPUT);
  pinMode(BI1, OUTPUT);

//  pinMode(PWMA, OUTPUT);
  
 
} // - END SETUP()

void loop() {

  digitalWrite(AI1, LOW);
  digitalWrite(BI1, HIGH);


  analogWrite(PWMA, 400);
  
} // - END LOOP()
