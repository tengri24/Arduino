#define BLYNK_TEMPLATE_ID "TMPL6RGS_ZwLc"
#define BLYNK_TEMPLATE_NAME "testLed"
#define BLYNK_AUTH_TOKEN "aguB8HSD_13cvpiGzdtK4U99BW2t5lER"
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = ".........";
char password[] = "12345678";
#define ledPin 14

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(115200);
  Serial.println("Starting setup...");
  Serial.print("Connecting to ");
  Serial.println(ssid);

  // In ra thông tin k?t n?i Blynk
  Serial.print("BLYNK_TEMPLATE_ID: ");
  Serial.println(BLYNK_TEMPLATE_ID);
  Serial.print("BLYNK_TEMPLATE_NAME: ");
  Serial.println(BLYNK_TEMPLATE_NAME);
  Serial.print("BLYNK_AUTH_TOKEN: ");
  Serial.println(auth);

  // K?t n?i Blynk
  Blynk.begin(auth, ssid, password);
}

void loop() {
  Blynk.run();
}

BLYNK_WRITE(V0) {
  int p = param.asInt();
  digitalWrite(ledPin, p);
}





