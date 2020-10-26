#include "LedControl.h"

int trigPin = 5;
int echoPin = 6;

LedControl lc=LedControl(11,13,10); 

void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);

Serial.begin(9600);
    lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,10);
  /* and clear the display */
  lc.clearDisplay(0);
  

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


 int i;
void loop() {
    Serial.print("Measurement: ");
 //printDistance();

  lc.setDigit(0, 1, i%10, false);
    lc.setDigit(0, 2, i/10%10, false);
      lc.setDigit(0, 3, i/100, false);
      i++;
      i=i%1000;
      Serial.println(i);
delay(500);

}
