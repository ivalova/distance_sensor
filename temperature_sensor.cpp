#include "temperature_sensor.h"
#include "logging.h"

temperatureSensor::temperatureSensor()
  : oneWire(sensorPin), sensors(&oneWire)
{
  // Start up the library
  sensors.begin();
}

float temperatureSensor::getTemperature(void)
{
  sensors.requestTemperatures();
  float temperature = sensors.getTempCByIndex(0);

  DEBUG_PRINTLN((String)"Measured temperature: " + temperature);
  
  return temperature;
}
