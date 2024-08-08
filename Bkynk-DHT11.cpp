#define BLYNK_TEMPLATE_ID "TMPL6G1Upz3oE"
#define BLYNK_TEMPLATE_NAME "dht11"
#define BLYNK_AUTH_TOKEN "Ajk8BoeKDdKz5dE35567BDQXAT0BKYdH"


#include <DHT.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


#define DHTPin  4      
#define DHTType  DHT11


#define ledPin 18
WidgetLED LED_ON_APP(V2);


char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = ".........";
char password[] = "12345678";


DHT dht(DHTPin, DHTType); // Khai báo thu vi?n chân c?m bi?n và ki?u c?m bi?n.


const unsigned long delayTime = 1000; // Th?i gian ch? gi?a các l?n d?c c?m bi?n


void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  dht.begin();
  Blynk.begin(auth, ssid, password);
}


void loop() {
  Blynk.run();
  // Ð?c d? li?u t? c?m bi?n
  float h = dht.readHumidity();
  float t = dht.readTemperature();


  // Ki?m tra tín hi?u tr? v? t? c?m bi?n
  if (isnan(h) || isnan(t)) {
    Serial.println("Không có giá tr? tr? v? t? c?m bi?n DHT");
  } else {
    // Hi?n th? d? li?u lên Serial Monitor
    displayData(h, t);
  }
 
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);


  delay(delayTime);
}


void displayData(float DoAm, float DoC) {
  Serial.print("Ð? ?m: ");
  Serial.print(DoAm);
  Serial.print("%  Nhi?t d?: ");
  Serial.print(DoC, 2);
  Serial.println("°C | ");
}


BLYNK_WRITE(V3) {
  int button = param.asInt();
  if(button == 1){
    digitalWrite(ledPin, HIGH);
    LED_ON_APP.on();
  }
  else{
    digitalWrite(ledPin, LOW);
    LED_ON_APP.off();
  }
}




