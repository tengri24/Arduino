int Red = 3, Green = 5, Blue = 6;
int _delay = 50;


void setup()
{
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Blue, OUTPUT);
 
  digitalWrite(Red, LOW);
  digitalWrite(Green, LOW);
  digitalWrite(Blue, LOW);
}


void loop()
{
 
  digitalWrite(Red, HIGH);
  delay(3000);
  digitalWrite(Red, LOW);
  delay(200);
 
  digitalWrite(Green, HIGH);
  delay(3000);
  digitalWrite(Green, LOW);
  delay(200);
 
  digitalWrite(Blue, HIGH);
  delay(3000);
  digitalWrite(Blue, LOW);
  delay(200);


  digitalWrite(Red, LOW);
  digitalWrite(Green, LOW);
  digitalWrite(Blue, LOW);
  delay(500);
 
  digitalWrite(Red, HIGH);
  digitalWrite(Green, HIGH);
  digitalWrite(Blue, HIGH);
  delay(2000);
 
  digitalWrite(Red, LOW);
  digitalWrite(Green, LOW);
  digitalWrite(Blue, LOW);
  delay(500);
 
  // �i?u khi?n s�ng t?t m? d?n
  int RedValue = 255;
  int GreenValue = 0;
  int BlueValue = 0;
 
  digitalWrite(Red, HIGH);
  digitalWrite(Green, LOW);
  digitalWrite(Blue, LOW);
 
  // �? m?i d?n xanh l� s�ng d?n, Xanh duong t?t
  for (int i = 0; i < 255; i++)
  {
    RedValue --;
    GreenValue ++;
   
    analogWrite(Red, RedValue);
    analogWrite(Green, GreenValue);
    delay(_delay);
  }


  // �? t?t Xanh l� m?i d?n, Xanh duong s�ng d?n
  RedValue = 0;
  GreenValue = 255;
  BlueValue = 0;


  for (int i = 0; i < 255; i++)
  {
    GreenValue --;
    BlueValue ++;
   
    analogWrite(Green, GreenValue);
    analogWrite(Blue, BlueValue);
    delay(_delay);
  }


// �? s�ng d?n, Xanh l� t?t Xanh duong t?t d?n
  RedValue = 0;
  GreenValue = 0;
  BlueValue = 255;


  for (int i = 0; i < 255; i++)
  {
    BlueValue --;
    RedValue ++;
   
    analogWrite(Blue, BlueValue);
    analogWrite(Red, RedValue);
    delay(_delay);
  }
  delay(5000);
}




