//code belongs to a YouTube tutorial on YouTube changel LogMaker360
//https://www.youtube.com/watch?v=uL3eWaehEQI
#include <IRremote.h>
#include <IRremoteInt.h>


IRsend irsend;

void setup()
{
  Serial.begin(9600);
}

void loop() {
  if (Serial.read() != -1) {
    for (int i = 0; i < 3; i++) {
      irsend.sendSony(0xa90, 12); // Sony TV power code
      delay(100);
    }
  }
} 

