#include <DHT.h>
#include <DHT_U.h>


#define DHTPin  6        // Chân xu?t tín hi?u c?a c?m bi?n n?i chân s? 6 Arduino
#define DHTType  DHT11   // Khai báo ki?u c?m bi?n là DHT11


DHT dht(DHTPin, DHTType); // Khai báo thu vi?n chân c?m bi?n và ki?u c?m bi?n.


const unsigned long delayTime = 1000; // Th?i gian ch? gi?a các l?n d?c c?m bi?n


void setup() {
  Serial.begin(9600);
  dht.begin();
}


void loop() {
  // Ð?c d? li?u t? c?m bi?n
  float DoAm = dht.readHumidity();
  float DoC = dht.readTemperature();
  float DoF = dht.readTemperature(true);


  // Ki?m tra tín hi?u tr? v? t? c?m bi?n
  if (isnan(DoAm) || isnan(DoC) || isnan(DoF)) {
    Serial.println("Không có giá tr? tr? v? t? c?m bi?n DHT");
  } else {
    // Hi?n th? d? li?u lên Serial Monitor
    displayData(DoAm, DoC, DoF);
  }


  delay(delayTime);
}


void displayData(float DoAm, float DoC, float DoF) {
  Serial.print("Ð? ?m: ");
  Serial.print(DoAm);
  Serial.print("%  Nhi?t d? Celsius | Fahrenheit : ");
  Serial.print(DoC, 1);
  Serial.print("°C | ");
  Serial.print(DoF, 1);
  Serial.println("°F");
}




