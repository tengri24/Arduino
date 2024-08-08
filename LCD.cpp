/*==========================================================================================
  Noi chan: SDA-A4, SCL-A5;
  https://maxpromer.github.io/LCD-Character-Creator/ trang web t?o k� t? d?c bi?t
  lcd.init()  : Kh?i t?o M�n h�nh M�n h�nh
  lcd.clear() : X�a m�n h�nh, dua con tr? v? v? tr� 0,0
  lcd.home()  : �ua con tr? v? v? tr� 0
  lcd.setCursor(x,y)  : �ua con tr? v? v? tr� c?t th? x, h�ng th? y
  lcd.noDisplay() : Kh�ng hi?n th? g� tr�n m�n h�nh c?
  lcd.display() : Hi?n th? l�n m�n h�nh
  lcd.noBlink() : Kh�ng nh?p nh�y con tr?
  lcd.blink() : Nh?p nh�y con tr?
  lcd.scrollDisplayLeft() : Cu?n m�n h�nh b�n tr�i
  lcd.scrollDisplayRight()  : Cu?n m�n h�nh b�n ph?i
  lcd.leftToRight() : K� t? s? hi?n th? t? ph�a b�n tr�i sang ph?i
  lcd.rightToLeft() : K� t? s? hi?n th? t? ph�a ph?i sang tr�i
  lcd.noBacklight() : T?t d�n n?n
  lcd.backlight() : C� d�n n?n
  lcd.write(x)  : M�n h�nh s? in ra k� t? th? x trong � nh? t? 0-7 c?a CGRAM
  lcd.createChar(location,charmap[])  : Hi?n th? m?t k� t? charmap[] b?t k�
  ==========================================================================================*/


#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);


byte gachNgang[]= {
  B00000,
  B00000,
  B00000,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000
};


void setup() {
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, gachNgang);
}


void loop() {
  lcd.setCursor(2, 0);
  lcd.print("Ngo Van Hai");
  delay(3000);
  lcd.clear();


  lcd.setCursor(2, 1);
  lcd.write(byte(0));
  lcd.setCursor(3, 1);
  lcd.print("B21DCVT176");
  delay(3000);
  lcd.clear();


  lcd.setCursor(2, 0);
  lcd.print("Ngo Van Hai");
  lcd.setCursor(2, 1);
  lcd.write(byte(0));
  lcd.setCursor(3, 1);
  lcd.print("B21DCVT176");
  delay(3000);
  lcd.clear();


}








