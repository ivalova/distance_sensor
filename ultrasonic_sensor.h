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
    static constexpr char buffer_size{20};

    int latest_buffer_index{0};
    unsigned long measurement_buffer[buffer_size];
};
