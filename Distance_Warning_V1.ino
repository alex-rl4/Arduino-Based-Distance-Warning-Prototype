#include "SR04.h"
int g1 = 13;
int g2 = 12;
int y1 = 11;
int y2 = 10;
int r1 = 9;
int r2 = 8;
int beeper = 7;
int echo = 3;
int trig = 2;
float dist;
bool beepOn = false;
unsigned long previousBeepTime = 0;
SR04 sr04 = SR04(3, 2);

void beep(int beepInterval) {
  unsigned long currentTime = millis();
  if (!beepOn && currentTime - previousBeepTime >= beepInterval) {
    digitalWrite(beeper, HIGH);
    previousBeepTime = currentTime;
    beepOn = true;
  }

  if (beepOn && currentTime - previousBeepTime >= 100) {
    digitalWrite(beeper, LOW);
    beepOn = false;
  }
}
void setup() {
  pinMode(g1, OUTPUT);
  pinMode(g2, OUTPUT);
  pinMode(y1, OUTPUT);
  pinMode(y2, OUTPUT);
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(beeper, OUTPUT);
}

void loop() {
  dist = sr04.Distance();
  while (dist <= 125) {
    unsigned long currentTime = millis();
    dist = sr04.Distance();
    if (dist > 105) {
      digitalWrite(g1, HIGH);
      digitalWrite(g2, LOW);
      digitalWrite(y1, LOW);
      digitalWrite(y2, LOW);
      digitalWrite(r1, LOW);
      digitalWrite(r2, LOW);
      beep(1000);
    }
    if (dist <= 105 && dist > 85) {
      digitalWrite(g1, HIGH);
      digitalWrite(g2, HIGH);
      digitalWrite(y1, LOW);
      digitalWrite(y2, LOW);
      digitalWrite(r1, LOW);
      digitalWrite(r2, LOW);
      beep(750);
    }
    if (dist <= 85 && dist > 65) {
      digitalWrite(g1, HIGH);
      digitalWrite(g2, HIGH);
      digitalWrite(y1, HIGH);
      digitalWrite(y2, LOW);
      digitalWrite(r1, LOW);
      digitalWrite(r2, LOW);
      beep(500);
    }
    if (dist <= 65 && dist > 45) {
      digitalWrite(g1, HIGH);
      digitalWrite(g2, HIGH);
      digitalWrite(y1, HIGH);
      digitalWrite(y2, HIGH);
      digitalWrite(r1, LOW);
      digitalWrite(r2, LOW);
      beep(300);
    }
    if (dist <= 45 && dist > 30) {
      digitalWrite(g1, HIGH);
      digitalWrite(g2, HIGH);
      digitalWrite(y1, HIGH);
      digitalWrite(y2, HIGH);
      digitalWrite(r1, HIGH);
      digitalWrite(r2, LOW);
      beep(100);
    }
    if (dist <= 30) {
      digitalWrite(g1, HIGH);
      digitalWrite(g2, HIGH);
      digitalWrite(y1, HIGH);
      digitalWrite(y2, HIGH);
      digitalWrite(r1, HIGH);
      digitalWrite(r2, HIGH);
      beep(50);
    }
    if(dist <=20){
      beep(25);
    }
  }
  digitalWrite(beeper, LOW);
  digitalWrite(g1, LOW);
  digitalWrite(g2, LOW);
  digitalWrite(y1, LOW);
  digitalWrite(y2, LOW);
  digitalWrite(r1, LOW);
  digitalWrite(r2, LOW);
}
