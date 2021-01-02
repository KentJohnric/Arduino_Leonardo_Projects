#include <Keyboard.h>
#include <Keypad.h>
int state;
int landState;
int smokeState;
#define but 4
#define landingGear 5
#define smoke 6
void setup() {
  Serial.begin(9600);
  pinMode(but,INPUT);
  pinMode(landingGear, INPUT);
  pinMode(smoke, INPUT);
}

void loop() {
  state = digitalRead(but);
  landState = digitalRead(landingGear);
  smokeState = digitalRead(smoke);
  if(state == HIGH){
    Keyboard.press('C');
    Serial.println("Boost Activated");
    delay(100);
    Keyboard.releaseAll();
  }
}
