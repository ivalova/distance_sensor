#include "displayController.h"
#include "ultrasonic_sensor.h"
#include "logging.h"

void setup()
{
#ifdef DEBUG
  Serial.begin (9600);
#endif
}

displayController display;
ultrasonicSensor distance_sensor;

void loop() 
{
  const unsigned long distance = distance_sensor.getDistanceInCm();
  display.setNumber(distance);
  
  DEBUG_PRINTLN((String)"Distance:" + distance);

  delay(150);
}
