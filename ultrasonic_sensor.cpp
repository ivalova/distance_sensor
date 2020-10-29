#include "ultrasonic_sensor.h"
#include "logging.h"

#include "Arduino.h"

ultrasonicSensor::ultrasonicSensor()
{
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
}

unsigned long ultrasonicSensor::getDistanceInCm(void)
{

  performNewDistanceMeasurement();

  unsigned long distance = getAverageDistanceFromBuffer();

  distance =  distance / 10 * 10; //lsb is 0

  return distance;
}

void ultrasonicSensor::performNewDistanceMeasurement(void)
{
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  unsigned long duration = pulseIn(echoPin, HIGH);
  unsigned long distance = (duration / 2.0) / 29.1;

  DEBUG_PRINTLN((String)"Measured distance:" + distance + " ");

  measurement_buffer[latest_buffer_index] = distance;
  latest_buffer_index++;
  latest_buffer_index = latest_buffer_index % buffer_size;
}

unsigned long ultrasonicSensor::getAverageDistanceFromBuffer()
{
  unsigned long sum = 0;

  for (int i = 0; i < buffer_size; i++)
  {
    sum += measurement_buffer[i];
  }

  return sum / buffer_size;
}
