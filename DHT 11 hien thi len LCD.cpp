#include <DHT.h>
#include <DHT_U.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h> // Thu vi?n Màn hình I2C


#define DHTPin 6           // Chân xu?t tín hi?u c?a c?m bi?n n?i chân s? 6 Arduino
#define DHTType DHT11      // Khai báo ki?u c?m bi?n là DHT11
#define I2C_ADDR 0x27      // Ð?a ch? I2C c?a LCD
#define LCD_COLUMNS 16     // S? c?t c?a LCD
#define LCD_ROWS 2         // S? hàng c?a LCD
#define DISPLAY_DELAY 3000 // Th?i gian ch? gi?a các l?n hi?n th?


DHT dht(DHTPin, DHTType); // Khai báo thu vi?n chân c?m bi?n và ki?u c?m bi?n.
LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_ROWS); // Khai báo d?a ch? I2C và kích thu?c LCD


void setup() {
  Serial.begin(9600);
  lcd.init();        // Kh?i d?ng LCD
  lcd.backlight();   // M? dèn màn hình
  dht.begin();       // Kh?i d?ng c?m bi?n DHT
}


void loop() {
  float DoAm = dht.readHumidity();       // Ð?c d? ?m môi tru?ng
  float DoC = dht.readTemperature();     // Ð?c nhi?t d? C
  float DoF = dht.readTemperature(true); // Ð?c nhi?t d? F


  // Ki?m tra tín hi?u tr? v? t? c?m bi?n
  if (isnan(DoAm) || isnan(DoC) || isnan(DoF)) {
    Serial.println("Không có giá tr? tr? v? t? c?m bi?n DHT");
    return;
  }


  // Hi?n th? d? li?u lên Serial Monitor
  displaySerialData(DoAm, DoC, DoF);


  // Hi?n th? d? li?u lên LCD
  displayLCDData(DoAm, DoC, "DO AM:", "NHIET DO C:");
  delay(DISPLAY_DELAY);
  lcd.clear();


  displayLCDData(DoAm, DoF, "DO AM:", "NHIET DO F:");
  delay(DISPLAY_DELAY);
  lcd.clear();
}


void displaySerialData(float DoAm, float DoC, float DoF) {
  Serial.print("Ð? ?m: ");
  Serial.print(DoAm);
  Serial.print("%  Nhi?t d? Celsius | Fahrenheit : ");
  Serial.print(DoC, 1);
  Serial.print("°C | ");
  Serial.print(DoF, 1);
  Serial.println("°F");
}


void displayLCDData(float DoAm, float DoTemp, const char* humidityLabel, const char* tempLabel) {
  lcd.setCursor(0, 0);
  lcd.print(humidityLabel);
  lcd.setCursor(7, 0);
  lcd.print(DoAm, 0);
  lcd.setCursor(10, 0);
  lcd.print("%");


  lcd.setCursor(0, 1);
  lcd.print(tempLabel);
  lcd.setCursor(12, 1);
  lcd.print(DoTemp, 1);
}




