#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

int i=0;
int o=0;

#define PIN 5 // D1 aus dem esp6266
#define NUMPIXELS 43 // Hier wird die Anzahl der angeschlossenen WS2812 LEDs bzw. NeoPixel angegeben

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int pause=100; // 100 Millisekunden Pause bis zur Ansteuerung der nächsten LED.

void setup() 
{
   Serial.begin(115200);
  pixels.begin(); // Initialisierung der NeoPixel
}

void loop() 
{
  Serial.print(i);
  Serial.println(" ");
pixels.setPixelColor(i, pixels.Color(0,150,0)); // Pixel leuchtet in der Farbe Grün
pixels.setPixelColor(i-1, pixels.Color(o,10,0)); // Der vorherige Pixel wird abgeschaltet
pixels.show(); // Durchführen der Pixel-Ansteuerung
  
//if (i==0) pixels.setPixelColor(39, pixels.Color(0,0,0)); // Im Fall von Pixel "0" muss die vorherige (39) ausgeschaltet werden.
//pixels.show(); // Durchführen der Pixel-Ansteuerung
delay (pause);
i=i+1; // Die Variable "i" wird um eine Zahl vergrößert. Die neue Zahl "i" ist dann die nächste LED im Led-Ring
o=o+1;
if (o==250) o=0;
if (i==44) i=0; // Wenn die Variable den Wert 40 erreicht hat, wird die Variable auf den Wert "0" zurück gesetzt, da die Nummerierung der LEDs nur von 0 bis 39 geht.
}
