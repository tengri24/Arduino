#include <DHT.h>
#include <DHT_U.h>


#define DHTPin  6        // Ch�n xu?t t�n hi?u c?a c?m bi?n n?i ch�n s? 6 Arduino
#define DHTType  DHT11   // Khai b�o ki?u c?m bi?n l� DHT11


DHT dht(DHTPin, DHTType); // Khai b�o thu vi?n ch�n c?m bi?n v� ki?u c?m bi?n.


const unsigned long delayTime = 1000; // Th?i gian ch? gi?a c�c l?n d?c c?m bi?n


void setup() {
  Serial.begin(9600);
  dht.begin();
}


void loop() {
  // �?c d? li?u t? c?m bi?n
  float DoAm = dht.readHumidity();
  float DoC = dht.readTemperature();
  float DoF = dht.readTemperature(true);


  // Ki?m tra t�n hi?u tr? v? t? c?m bi?n
  if (isnan(DoAm) || isnan(DoC) || isnan(DoF)) {
    Serial.println("Kh�ng c� gi� tr? tr? v? t? c?m bi?n DHT");
  } else {
    // Hi?n th? d? li?u l�n Serial Monitor
    displayData(DoAm, DoC, DoF);
  }


  delay(delayTime);
}


void displayData(float DoAm, float DoC, float DoF) {
  Serial.print("�? ?m: ");
  Serial.print(DoAm);
  Serial.print("%  Nhi?t d? Celsius | Fahrenheit : ");
  Serial.print(DoC, 1);
  Serial.print("�C | ");
  Serial.print(DoF, 1);
  Serial.println("�F");
}




