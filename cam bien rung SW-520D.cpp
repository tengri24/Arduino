int Sensor =A0;
int led = 13;
int Value;


void setup()
{
  Serial.begin(9600);
  pinMode(Sensor, INPUT);
  pinMode(led, OUTPUT);
}


void loop()
{
  Value = analogRead(Sensor);
  Serial.print("Value read from sensor: ");
  Serial.println(Value);
  delay(50);
 
  if (Value < 1021)
  {
    digitalWrite(led, HIGH);
    delay(3000);
  }
  else
  {
    digitalWrite(led, LOW);
  }
}


