/*==========================================================================================
  Noi chan: SDA-A4, SCL-A5;
  https://maxpromer.github.io/LCD-Character-Creator/ trang web t?o ký t? d?c bi?t
  lcd.init()  : Kh?i t?o Màn hình Màn hình
  lcd.clear() : Xóa màn hình, dua con tr? v? v? trí 0,0
  lcd.home()  : Ðua con tr? v? v? trí 0
  lcd.setCursor(x,y)  : Ðua con tr? v? v? trí c?t th? x, hàng th? y
  lcd.noDisplay() : Không hi?n th? gì trên màn hình c?
  lcd.display() : Hi?n th? lên màn hình
  lcd.noBlink() : Không nh?p nháy con tr?
  lcd.blink() : Nh?p nháy con tr?
  lcd.scrollDisplayLeft() : Cu?n màn hình bên trái
  lcd.scrollDisplayRight()  : Cu?n màn hình bên ph?i
  lcd.leftToRight() : Kí t? s? hi?n th? t? phía bên trái sang ph?i
  lcd.rightToLeft() : Kí t? s? hi?n th? t? phía ph?i sang trái
  lcd.noBacklight() : T?t dèn n?n
  lcd.backlight() : Có dèn n?n
  lcd.write(x)  : Màn hình s? in ra kí t? th? x trong ô nh? t? 0-7 c?a CGRAM
  lcd.createChar(location,charmap[])  : Hi?n th? m?t kí t? charmap[] b?t kì
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








