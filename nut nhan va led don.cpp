const int button1Pin = 2;
const int button2Pin = 3;
const int led1 = 4;
const int led2 = 5;
int button1State = 0;
int button2State = 0;


void setup(){
  Serial.begin(9600);
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}


void loop(){
  button1State = digitalRead(button1Pin);
  if(button1State == 1){
    digitalWrite(led1, HIGH);
  }
  else{
    digitalWrite(led1, LOW);
  }
  Serial.print("Trang thai nut nhan 1: ");
  Serial.println(button1State);
  delay(1000);
  button2State = digitalRead(button2Pin);
  if(button2State == 0){
    digitalWrite(led2, HIGH);
  }
  else{
    digitalWrite(led2, LOW);
  }
  Serial.print("Trang thai nut nhan 2: ");
  Serial.println(button2State);
  delay(1000);
}


