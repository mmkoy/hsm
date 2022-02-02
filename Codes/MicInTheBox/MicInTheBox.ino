
/////////////////////////////////////////////////////////
//
// Servo boxi mikrofonilla: Mic-in-The-Box
//
// Author     : Jani Hirvinen, jani@jdronics.fi
// Version    : v1.0 20-09-2021
//
/////////////////////////////////////////////////////////
// Harrastamisen Malli Esimerkki
//
// Servo ja Mikrofonim yhteiskäyttö esimerkki. Kovasta äänestä
// kansi joko aukeaa tai sulkeutuu. 0.5 sek viive mikrofonin
// kuuntelu operaatioiden välissä.
//
///////////////////////////////////////////////////////////
//
//  Kytkentä:
// - Servo GND    - GND
// - Servo VCC    - 5V
// - Servo Signal - PWM Pin (esimerkiksi D9)
// - Mikki Vcc    - 5V
// - Mikki GND    - GND
// - Mikki AOut   - A0 Analooginen sisään tulo
//
///////////////////////////////////////////////////////////


/////////////////////
// INCLUDES
#include <Servo.h>          // Sisällytetään Servo.h headeri tiedosto servon käyttöä varten


/////////////////////
// Defines and declarations

#define SRV1PIN         9   // Servo on D9
#define MIC             A0  // Mikin sisääntulo on A0

#define LID_OPEN        10  // Servon asento kun kansi on täysin auki
#define LID_CLOSE       80  // Servon asento kun kansi on kiinni
#define LID_FULLCLOSE   90  // Servon asento kun laite käynnistyy

#define MIC_TRESHOLD    60  // Mikin "kovaääni" kynnys

#define WAITTIME        800 // Odotus aika (0.5sek) ennenkuin mikkiä uudestaan kuunnellaan

#define TRUE            1   // Perinteinen TRUE määritys
#define FALSE           0   // Perinteinen FALSE määritys

// Kiinnitetään Servo objekti srv1 muutujaan
Servo srv1;


/////////////////////
// Globaalit muuttujat
boolean lid_status       = FALSE; // Kannen tila muuttuja
int mic_in               = 0;     // Mikin viimeisin "äänenvoimakkuus" muuttuja

unsigned long lastChange = 0;     // Muuttuja kellonajalle jolloin teimme viimeisimmän muutoksen kannen asentoon
unsigned long nowTime    = 0;     // Muuttuja jota käytetään tilapäisesti ajankulu laskuihin

//////////////////////
// SETUP(), Määritellään alku parametrit
// ja alustetaan objektit, portit jne

void setup() {

  srv1.attach(SRV1PIN);             // Kiinnitetään SRV1PIN srv1 objektiin
  srv1.write(LID_FULLCLOSE);        // Siirretään servo armi alimpaan asentoon

} // - END SETUP()

void loop() {

  // Kuulostellaan mikkiä
  mic_in = analogRead(MIC);

  // Tarkistetaan että olikos mikin kuulossa tarpeeksi kova ääni
  // tarkistetaan että onko "mic_in" suurempi kuin MIC_TRESHOLD
  if (mic_in > MIC_TRESHOLD) {

    // Kun olemme täällä niin mic_in oli suurempi kuin MIC_TRESHOLD
    // luetaan viimeisin millisekunttien määrä käynnistymisestä ja tallennetaan
    // se nowTime muuttujaan
    nowTime = millis();

    // Tarkistetaan että onko aikaa kulunut tarpeeksi siitä kuin viimeksi
    // teimme muutoksia kannen tilaan. Eli:
    // onko notTime - lastChange:n erotus suurempi kuin asetettu WAITTIME
    if (nowTime - lastChange >= WAITTIME) {

      // Aikaa on kulunut tarpeeksi viimeisestä muutoksesta joten teemme uuden
      // ja samalla siirrämme nowTime tiedon lastChange muuttujaan.
      lastChange = nowTime;

      // Tarkistamme että onko lid_status TRUE vai FALSE. Jokotai, teemme toisen
      // ja muutamme statuksen myös vastakkaiseksi.
      if (lid_status) {

        // Viimeiksi lid_status oli TRUE joten nyt muutamme sen FALSE:ksi
        lid_status = FALSE;
        srv1.write(LID_CLOSE);  // Ja sitten laitetaan viellä kansi kiinni

      } else {

        // lid_status olikin FALSE joten laitamme seuraavan statuksen TRUE:ksi
        lid_status = TRUE;
        srv1.write(LID_OPEN);  // Ja sitten viellä avamme kannen
      }
    }
  }
} // - END LOOP()
