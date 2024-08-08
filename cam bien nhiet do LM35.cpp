#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x27 for a 16 chars and 2 line display


int _LM35 = A0; //the analog pin the LM35 Vout
float TempC;
float TempF;  


byte Do[] = {
  B11000,
  B11000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};  


void setup() {
  Serial.begin(9600);  // Start the serial connection with the computer
  lcd.init();
  lcd.backlight();    // To view the result open the serial monitor
  lcd.createChar(0, Do);
}


void loop() {
  float TempC = readTemperatureC();
  float TempF = celsiusToFahrenheit(TempC);


  Serial.print(TempC); Serial.println(" degrees C");
  Serial.print(TempF); Serial.println(" degrees F");
 
  displayTemperature("C", TempC);
  delay(5000);
 
  displayTemperature("F", TempF);
  delay(5000);
}


float readTemperatureC() {
  int Val_LM35 = analogRead(_LM35);  // Getting the voltage value from the temperature sensor
  float Volt = (Val_LM35 * 5000.0) / 1024.0; // Converting that value to mVolt
  return Volt / 10.0; // Convert mVolt to Celsius
}


float celsiusToFahrenheit(float TempC) {
  return (TempC * 9.0 / 5.0) + 32.0; // Convert Celsius to Fahrenheit
}


void displayTemperature(String unit, float temperature) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("HaiNV-B21DCVT176");
  lcd.setCursor(2, 1);
  lcd.print("Temp: ");
  lcd.setCursor(8, 1);
  lcd.print(temperature);
  lcd.setCursor(13, 1);
  lcd.write(byte(0));
  lcd.setCursor(14, 1);
  lcd.print(unit);
}




