const int button = 2;
int led[] = {3, 4, 5, 6};
int buttonState = 0;
int cnt = 0;


void setup(){
  for(int i=0; i<=3; i++){
    pinMode(led[i], OUTPUT);
  }
  pinMode(button, INPUT_PULLUP);
}


void loop(){
  buttonState = digitalRead(button);
  if(buttonState == LOW) cnt++; // Nút nh?n s? d?c LOW khi nh?n
  if(cnt == 0){
    for(int i=0; i<=3; i++){
      digitalWrite(led[i], LOW);
    }
  }
  for (int i=0; i<=3; i++) {
  if (cnt == i + 1){
    digitalWrite(led[i], HIGH);
  }
  else{
    digitalWrite(led[i], LOW);
    }
  }
  if(cnt > 4) cnt = 0;
  delay(300);
}






