#include "displayController.h"
#include "ultrasonic_sensor.h"

#define DEBUG

#ifdef DEBUG
 #define DEBUG_PRINT(x)  Serial.println (x)
#else
 #define DEBUG_PRINT(x)
#endif

void setup() {
  
#ifdef DEBUG
  Serial.begin (9600);
#endif
}

displayController display;
ultrasonicSensor distane_sensor;

void loop() {

  const unsigned long distance = distane_sensor.getDistanceInCm();
  display.setNumber(distance);
  Serial.print(" ");
  Serial.println(distance);

  delay(50);

}
