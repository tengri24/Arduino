#include <Stepper.h>
#include <IRremote.hpp>


const int stepRevolution = 2048; // So buoc trong mot vong quay
Stepper myStepper1 = Stepper(stepRevolution, 8, 10, 9, 11);
Stepper myStepper2 = Stepper(stepRevolution, 8, 10, 9, 11);
Stepper myStepper3 = Stepper(stepRevolution, 8, 10, 9, 11);
const int IrPin = 2;


void setup() {
  Serial.begin(9600);
  myStepper1.setSpeed(5);
  myStepper2.setSpeed(10);
  myStepper3.setSpeed(15);
  IrReceiver.begin(2, true, 3);
}


void loop() {
  if(IrReceiver.decode()){
    uint32_t dataRemote = IrReceiver.decodedIRData.decodedRawData;
    if(dataRemote > 0){
      Serial.println(dataRemote);
      switch(dataRemote){
        case 4077715200:
        myStepper1.step(stepRevolution);
        break;


        case 3877175040:
        myStepper2.step(stepRevolution);
        break;


        case 2707357440:
        myStepper3.step(stepRevolution);
        break;


        case 4144561920:
        myStepper1.step(stepRevolution);
        myStepper2.step(stepRevolution);
        myStepper3.step(stepRevolution);
        break;
      }
    }
    IrReceiver.resume();
  }


}




