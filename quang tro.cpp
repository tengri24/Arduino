int quangTro = A0;


void setup(){
  Serial.begin(9600);
  pinMode(quangTro, INPUT);
}


void loop(){
  int value = analogRead(quangTro);
  Serial.print("Gia tri doc duoc la: ");
  Serial.println(value);
  delay(500);
}


