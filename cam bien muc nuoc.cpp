const int Sensor = A0;
int SensorValue = 0;
int RedLed = 2, YellowLed = 3, Buzzer = 4;


void setup()
{
    pinMode(RedLed,OUTPUT);
    pinMode(YellowLed,OUTPUT);
    pinMode(Buzzer,OUTPUT);
    Serial.begin(9600);
}


void loop()
{
    SensorValue = analogRead(Sensor);
    Serial.print("Sensor = ");
    Serial.print(SensorValue);
    Serial.println();
    delay(50);


if((SensorValue >= 150)&&(SensorValue <= 600))
{
    digitalWrite(RedLed , HIGH);
    delay(50);
}
else if((SensorValue >= 601)&&(SensorValue <= 650))
{
    digitalWrite(YellowLed , HIGH);
    digitalWrite(Buzzer , HIGH);
    delay(50);
}


else
  { digitalWrite(RedLed , LOW);
    digitalWrite(YellowLed , LOW);
    digitalWrite(Buzzer , LOW);
    delay(50); }
}




