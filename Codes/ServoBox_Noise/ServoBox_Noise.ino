/////////////////////////////////////////////////////////
//
// Servo boxi mikrofonilla
//
// Author     : Jani Hirvinen, jani@jdronics.fi
// Version    : v1.0 8-9-2021
//
/////////////////////////////////////////////////////////
// Harrastamisen Malli Demo
//
// Testi sketchi jolla käytetään Servo Boxin kantta
//
///////////////////////////////////////////////////////////
//
//  Kytkentä:
// - Servo GND    - GND
// - Servo VCC    - 5V
// - Servo Signal - PWM Pin (esimerkiksi D9)
//
///////////////////////////////////////////////////////////


/////////////////////
// INCLUDES
#include <Servo.h>


/////////////////////
// Defines and declarations

#define SRV1PIN 9
#define MIC A0

#define LID_OPEN 10

#define LID_CLOSE 80
#define MIC_TRESHOLD 60
#define WAITTIME 1000

#define TRUE 1
#define FALSE 0

// Kiinnitetään Servo objekti srv1 objektiin
Servo srv1;


/////////////////////
// Globaalit muuttujat
int lid_status;
int mic_in;

unsigned long lastChange = 0;
unsigned long nowTime;

void setup() {
  srv1.attach(SRV1PIN);  // Kiinnitetään SRV1PIN srv1 objektiin
  srv1.write(80);

  Serial.begin(115200);

}

void loop() {

  mic_in = analogRead(MIC);
  if (mic_in > MIC_TRESHOLD) {
    //Serial.println(analogRead(MIC));

    nowTime = millis();
    if (nowTime - lastChange >= WAITTIME) {
      lastChange = nowTime;
      Serial.print(mic_in);
      if (lid_status) {
        lid_status = FALSE;
        srv1.write(LID_CLOSE);
      } else {
        lid_status = TRUE;
        srv1.write(LID_OPEN);
      }

    }
  }

  // Loopyloop.. hypätään loop() alkuun
}
