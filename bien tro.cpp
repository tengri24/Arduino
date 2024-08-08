int Potentiometer = A0;
int Value;
int RedLed= 2;
int YellowLed= 3;
int GreenLed= 4;


void setup()
{
  Serial.begin(9600);
  pinMode(Potentiometer,INPUT);
  pinMode(RedLed,OUTPUT);
  pinMode(YellowLed,OUTPUT);
  pinMode(GreenLed,OUTPUT);
}


void loop()
{
  Value = analogRead(Potentiometer);
  Serial.print("Value read from potentiometer: ");
  Serial.println(Value);
 
  if((Value >= 100)&&(Value <= 400))
{
    digitalWrite(RedLed , HIGH);
    digitalWrite(YellowLed , LOW);
    digitalWrite(GreenLed , LOW);
    delay(50);
}
else if((Value >= 401)&&(Value <= 800))
{
    digitalWrite(RedLed , HIGH);
    digitalWrite(YellowLed , HIGH);
    digitalWrite(GreenLed , LOW);
    delay(50);
}


else if((Value >= 801)&&(Value <= 1023))
{
    digitalWrite(RedLed , HIGH);
    digitalWrite(YellowLed , HIGH);
    digitalWrite(GreenLed , HIGH);
    delay(50);
}


else
  {
    digitalWrite(RedLed , LOW);
    digitalWrite(YellowLed , LOW);
    digitalWrite(GreenLed , LOW);
    delay(50);
}
}




