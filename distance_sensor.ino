#include "displayController.h"

int trigPin = 5;
int echoPin = 6;



void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);



}

void printDistance(void)
{

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  auto duration = pulseIn(echoPin, HIGH);
  auto  cm = (duration / 2) / 29.1;   // Divide by 29.1 or multiply by 0.0343
  Serial.println(cm);

  delay(100);
}

displayController display;

void loop() {
  static int i{0};

  display.setNumber(i);

  i++;
  i = i % 1000;
  Serial.println(i);

  delay(300);

}
