#ifndef TEMPERATURE_SENSOR_H_
#define TEMPERATURE_SENSOR_H_

#include <OneWire.h>
#include <DallasTemperature.h>


class temperatureSensor {
  public:
    temperatureSensor();

    // Gets current temperature in degrees celius
    float getTemperature(void);

  private:
    // Setup a oneWire instance to communicate with any OneWire devices
    OneWire oneWire;

    // Pass our oneWire reference to Dallas Temperature.
    DallasTemperature sensors;

    static constexpr uint8_t sensorPin{8};
};

#endif //TEMPERATURE_SENSOR_H_
