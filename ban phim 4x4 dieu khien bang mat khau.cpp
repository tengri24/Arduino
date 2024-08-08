#include <Keypad.h>


const byte ROWS = 4;
const byte COLS = 4;
char password[4];
char inPassword[] = "123";
char offPassword[] = "321";
int buzzer = 10;
int rled = 11;
int yled = 12;
int i=0, cnt=0;


char hexaKeys[ROWS][COLS] = {
  {'0','1','2','3'},
  {'4','5','6','7'},
  {'8','9','A','B'},
  {'C','D','E','F'}
};
byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {6, 7, 8, 9};


Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);


void setup(){
  Serial.begin(9600);
  pinMode(rled,OUTPUT);
  pinMode(yled,OUTPUT);
  pinMode(buzzer,OUTPUT);
}
 
void loop(){
  char enterKey = customKeypad.getKey();
  if(enterKey){
    password[i] = enterKey;
    i++, cnt++;
    tone(buzzer, 2000, 200);
    Serial.println(password);
  }
  if(cnt==3){
    if(!strcmp(password, inPassword)){
        digitalWrite(rled, HIGH);
        digitalWrite(yled, LOW);
        Serial.println("Bat den.");
        delay(100);
        tone(buzzer, 2000, 200);
        i=0;
    }
    if(!strcmp(password, offPassword)){
      digitalWrite(yled, LOW);
      digitalWrite(rled, LOW);
      Serial.println("Tat den.");
      delay(100);
      tone(buzzer, 2000, 200);
      i=0;
    }
    if(strcmp(password, inPassword)){
      if(strcmp(password, offPassword)){
        digitalWrite(yled, HIGH);
        Serial.println("Nhap sai mat khau, yeu cau nhap lai.");
        delay(100);
        tone(buzzer, 2000, 200);
        i=0;
      }
    }
    cnt=0;
  }
}




