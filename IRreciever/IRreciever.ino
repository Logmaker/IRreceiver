/*
code belongs to a YouTube tutorial on YouTube changel LogMaker360
https://www.youtube.com/watch?v=uL3eWaehEQI
*/
#include <IRremote.h>
#include <IRremoteInt.h>


int counter = 0;
int LED =13;
int RECV_PIN = 11;
unsigned int timeOfIncoming;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
     
     Serial.println(results.value, HEX);
           if(results.value == 0xa90){ //if the button press equals the hex value 0xA90
               Serial.println("counted: 1");
               
               timeOfIncoming = millis();
               counter++;
               irrecv.resume();
               irrecv.decode(&results);
                         
                if(results.value == 0xa90 && timeOfIncoming+1000 > millis()){
                 Serial.println(results.value, HEX);
                 Serial.println("     counted: 2");
                 
                 counter++;
                 irrecv.resume();
                 irrecv.decode(&results);
                                   
                                    
                                   if(results.value == 0xa90 && timeOfIncoming+1000 > millis()){
                                  Serial.println(results.value, HEX);
                                  Serial.println("       counted: 3");
                                  counter++;
                                  irrecv.resume();
                                    }
                }

           }                        
               
    
    if(counter == 3){
      Serial.println("               TV on");
      digitalWrite(LED, HIGH);
      delay(4000);
      digitalWrite(LED, LOW);
    }
    irrecv.resume(); // Receive the next value
    counter = 0;
    timeOfIncoming = 0;
  }
  }

