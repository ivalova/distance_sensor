#include "ultrasonic_sensor.h"

#include "Arduino.h"

ultrasonicSensor::ultrasonicSensor()
{
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
}

unsigned long ultrasonicSensor::getDistanceInCm(void)
{

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  unsigned long duration = pulseIn(echoPin, HIGH);
  unsigned long distance = (duration / 2.0) / 29.1;
  Serial.print(distance);

  measurement_buffer[latest_buffer_index] = distance;
  latest_buffer_index++;
  latest_buffer_index=latest_buffer_index%buffer_size;

  unsigned long sum = 0;
  for(char i=0;i<buffer_size;i++)
  {
    sum += measurement_buffer[i];
  }
  return sum / buffer_size;
}
