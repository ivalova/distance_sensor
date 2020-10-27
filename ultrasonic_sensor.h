class ultrasonicSensor
{
  public:
    ultrasonicSensor();
    unsigned long getDistanceInCm(void);

    private:
    static constexpr int trigPin{5};
    static constexpr int echoPin{6};
    static constexpr char buffer_size{40};

    char latest_buffer_index{0};
    unsigned long measurement_buffer[buffer_size];
};
