#include "OneButton.h"
int nutNhan = 2;
int led[] = {3,4,5,6,7,8};
OneButton Mybutton(nutNhan, true);


void setup() {
  for(int i=0; i<6; i++){
    pinMode(led[i], OUTPUT);
  }


  Mybutton.attachClick(nhanDon);
  Mybutton.attachDoubleClick(nhanKep);
  Mybutton.attachLongPressStart(nhanGiu);
  Mybutton.attachDuringLongPress(nhanGiuLau);
  Mybutton.attachLongPressStop(nhanTha);
  Mybutton.attachMultiClick(nhanNhieuLan);


}


void loop() {
  Mybutton.tick();
}


void nhanDon(){
  digitalWrite(led[0], !digitalRead(led[0]));
}
void nhanKep(){
  for(int i=0; i<=10; i++){
    digitalWrite(led[1], HIGH);
    delay(500);
    digitalWrite(led[1], LOW);
    delay(50);
  }
}
void nhanGiu(){
  for(int i=0; i<255; i++){
    analogWrite(led[2], i);
    delay(10);
  }
  digitalWrite(led[2], LOW);
}
void nhanGiuLau(){
  digitalWrite(led[3], HIGH);
  delay(2000);
  digitalWrite(led[3], LOW);
  delay(50);
}
void nhanTha(){
  digitalWrite(led[4], HIGH);
  delay(2000);
  digitalWrite(led[4], LOW);
  delay(50);
}
void nhanNhieuLan(){
  digitalWrite(led[5], HIGH);
  delay(2000);
  digitalWrite(led[5], LOW);
  delay(50);
}




