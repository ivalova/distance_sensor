#include "displayController.h"
#include "ultrasonic_sensor.h"
#include "temperature_sensor.h"
#include "logging.h"

#define SWITCH_PIN 2

void setup()
{
  pinMode(SWITCH_PIN,INPUT_PULLUP);
#ifdef DEBUG
  Serial.begin (9600);
#endif
}

displayController display;
ultrasonicSensor distance_sensor;
temperatureSensor temperature_sensor;

void loop()
{
  auto read_temperature = digitalRead(SWITCH_PIN);
  int display_value{0};

  if(read_temperature == true)
  {
      display_value = static_cast<int>(temperature_sensor.getTemperature());
      
  }
  else
  {
    display.clearDisplay(); // Display causes voltage drop which interferes with distance sensor
  display_value = distance_sensor.getDistanceInCm();
 
  DEBUG_PRINTLN((String)"Displayed distance:" + display_value);
  }
  
 display.setNumber(display_value);

  delay(150);
  
}
