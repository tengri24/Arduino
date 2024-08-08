int led[] = {2,3,4,5,6,7,8,9};
int n=7, p=4;
void setup() {
  for(int i=0; i<=7; i++){
    pinMode(led[i], OUTPUT);
  }
}


void loop() {


  nhapNhay();
  delay(2000);


  traiPhai();
  delay(2000);


  phaiTrai();
  delay(2000);


  tatDanTrai();
  delay(2000);


  tatDanPhai();
  delay(2000);


  ngoaiVaoTrong();
  delay(2000);


  trongRaNgoai();
  delay(2000);


  xenKe();
  delay(2000);
}


void nhapNhay(){
  for(int i=0; i<=7; i++){
    for(int j=0; j<=7; j++){
      digitalWrite(led[j], LOW);
    }
    delay(500);
    for(int j=0; j<=7; j++){
      digitalWrite(led[j], HIGH);
    }
    delay(500);
  }
  for(int i=0; i<=7; i++){
    digitalWrite(led[i], LOW);
  }
  delay(500);
}


void traiPhai(){
  for(int i=0; i<=7; i++){
    for(int j=0; j<=7; j++){
      digitalWrite(led[j], LOW);
    }
    digitalWrite(led[i], HIGH);
    delay(500);
  }
  for(int i=0; i<=7; i++){
    digitalWrite(led[i], LOW);
  }
  delay(500);
}


void phaiTrai(){
  for(int i=7; i>=0; i--){
    for(int j=0; j<=7; j++){
      digitalWrite(led[j], LOW);
    }
    digitalWrite(led[i], HIGH);
    delay(500);
  }
  for(int i=0; i<=7; i++){
    digitalWrite(led[i], LOW);
  }
  delay(500);
}


void tatDanTrai(){
  for(int i=0; i<=7; i++){
    digitalWrite(led[i], HIGH);
    delay(500);
  }
  for(int i=0; i<=7; i++){
    digitalWrite(led[i], LOW);
    delay(500);
  }
  for(int i=0; i<=7; i++){
    digitalWrite(led[i], LOW);
  }
  delay(500);
}


void tatDanPhai(){
  for(int i=7; i>=0; i--){
    digitalWrite(led[i], HIGH);
    delay(500);
  }
  for(int i=7; i>=0; i--){
    digitalWrite(led[i], LOW);
    delay(500);
  }
  for(int i=0; i<=7; i++){
    digitalWrite(led[i], LOW);
  }
  delay(500);
}


void ngoaiVaoTrong(){
  n = 7; // Thi?t l?p l?i giá tr? ban d?u cho n
  for(int i=0; i<=3; i++){
    digitalWrite(led[i], HIGH);
    digitalWrite(led[n], HIGH); n--;
    delay(500);
  }
  n = 7; // Thi?t l?p l?i giá tr? ban d?u cho n
  for(int i=0; i<=3; i++){
    digitalWrite(led[i], LOW);
    digitalWrite(led[n], LOW); n--;
    delay(500);
  }
  for(int i=0; i<=7; i++){
    digitalWrite(led[i], LOW);
  }
  delay(500);
}


void trongRaNgoai(){
  p = 4; // Thi?t l?p l?i giá tr? ban d?u cho p
  for(int i=3; i>=0; i--){
    digitalWrite(led[i], HIGH);
    digitalWrite(led[p], HIGH); p++;
    delay(500);
  }
  p = 4; // Thi?t l?p l?i giá tr? ban d?u cho p
  for(int i=3; i>=0; i--){
    digitalWrite(led[i], LOW);
    digitalWrite(led[p], LOW); p++;
    delay(500);
  }
  for(int i=0; i<=7; i++){
    digitalWrite(led[i], LOW);
  }
  delay(500);
}


void xenKe(){
  for(int i=0; i<=7; i++){
    for(int j=0; j<=7; j+=2){
      digitalWrite(led[j], HIGH);
    }
    delay(500);
    for(int j=0; j<=7; j++){
     digitalWrite(led[j], LOW);
    }
    for(int j=1; j<=7; j+=2){
      digitalWrite(led[j], HIGH);
    }
    delay(500);
    for(int j=0; j<=7; j++){
     digitalWrite(led[j], LOW);
    }
  }
}




