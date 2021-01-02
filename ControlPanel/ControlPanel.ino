#include <Keyboard.h>
#include <Keypad.h>
int onToggle = A0;
int cPush = A1;
int toggle1 = A2;
int toggle2 = A3;
int toggle31 = A4;
int toggle32 = A5;
int dPush = 2;
int toggle41 = 3;
int led5 = 8;
int led4 = 9;
int led3 = 10;
int led2 = 11;
int led1 = 12;
int go = 7;
int back = 6;
bool onbutton = false;
void setup() {
  Serial.begin(9600);
  pinMode(onToggle, INPUT);
  pinMode(cPush, INPUT);
  pinMode(toggle1, INPUT);
  pinMode(toggle2, INPUT);
  pinMode(toggle31, INPUT);
  pinMode(toggle32, INPUT);
  pinMode(dPush, INPUT);
  pinMode(toggle41, INPUT);
  pinMode(led5, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(go, INPUT);
  pinMode(back, INPUT);
}

void loop() {
  int onToggleState = digitalRead(onToggle);
  if(onToggleState == HIGH){
    digitalWrite(led1, HIGH);
    delay(500);
    digitalWrite(led2, HIGH);
    delay(500);
    digitalWrite(led3, HIGH);
    delay(500);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    onbutton = true;
  }
  while(onbutton){
    int onToggleState = digitalRead(onToggle);
    int cPushState = digitalRead(cPush);
    int toggle1State = digitalRead(toggle1);
    int toggle2State = digitalRead(toggle2);
    int toggle31State = digitalRead(toggle31);
    int toggle32State = digitalRead(toggle32);
    int dPushState = digitalRead(dPush);
    int toggle41State = digitalRead(toggle41);
    int goState = digitalRead(go);
    int backState = digitalRead(back);   
    if(onToggleState == LOW){
      onbutton = false;
    }
    if(goState == HIGH){
      Keyboard.press('W');
      Serial.println("Throttle Up");
      delay(100);
      Keyboard.releaseAll();
    }
    if(backState == HIGH){
      Keyboard.press('S');
      Serial.println("Throttle Down");
      delay(100);
      Keyboard.releaseAll();
    }
    if(toggle1State == HIGH){
      Keyboard.press('X');
      Serial.println("Gear Down");
      digitalWrite(led1, HIGH);
      delay(500);
      Keyboard.releaseAll();
    }
    if(toggle2State == HIGH){
      Keyboard.press('Z');
      Serial.println("Smoke");
      digitalWrite(led2, HIGH);
      delay(500);
      Keyboard.releaseAll();
    }
    if(toggle32State == HIGH){
      digitalWrite(led3, HIGH);
      if(dPushState == HIGH){
        Keyboard.press(KEY_LEFT_SHIFT);
        Serial.println("Boost");
        delay(100);
        Keyboard.releaseAll();
      }
    }
    if(toggle32State == LOW){
      digitalWrite(led3, LOW);
    }
    if(toggle1State == LOW){
      digitalWrite(led1, LOW);
    }
    if(toggle2State == LOW){
      digitalWrite(led2, LOW);
    }
  }
}
