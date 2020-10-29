#ifndef ULTRASONIC_SENSOR_H_
#define ULTRASONIC_SENSOR_H_

class ultrasonicSensor
{
  public:
    ultrasonicSensor();
    unsigned long getDistanceInCm(void);

  private:
    void performNewDistanceMeasurement(void);
    unsigned long getAverageDistanceFromBuffer(void);

    static constexpr int trigPin{3};
    static constexpr int echoPin{4};
    static constexpr char buffer_size{10};

    int latest_buffer_index{0};
    unsigned long measurement_buffer[buffer_size];
};

#endif //ULTRASONIC_SENSOR_H_
