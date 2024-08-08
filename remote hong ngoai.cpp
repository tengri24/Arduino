#include <IRremote.hpp>
const int IrPin = 2;
int led[] = {3, 4, 5, 6};
unsigned long lastTime = millis();


void setup() {
  Serial.begin(9600);
  for(int i=0; i<=3; i++){
    pinMode(led[i], OUTPUT);
  }
  IrReceiver.begin(2, true, 8);
}


void loop() {
  if(IrReceiver.decode()){
    uint32_t dataRemote = IrReceiver.decodedIRData.decodedRawData;
    if(dataRemote > 0){
      Serial.println(dataRemote);
      if(millis() - lastTime > 250){ // Thoi gian nghi giua 2 lan bam
        switch(dataRemote){


          case 4077715200:
          digitalWrite(led[0], !digitalRead(led[0]));
          break;


          case 3877175040:
          digitalWrite(led[1], !digitalRead(led[1]));
          break;


          case 2707357440:
          digitalWrite(led[2], !digitalRead(led[2]));
          break;


          case 4144561920:
          digitalWrite(led[3], !digitalRead(led[3]));
          break;


          case 3125149440:
          for(int i=0; i<=3; i++)
            digitalWrite(led[i], LOW);
          break;


          case 3091726080:
          for(int i=0; i<=3; i++)
            digitalWrite(led[i], HIGH);
          break;
        }
      }
    }
    lastTime = millis();
    IrReceiver.resume(); // Cho phép nh?n giá tr? ti?p theo
  }
}




