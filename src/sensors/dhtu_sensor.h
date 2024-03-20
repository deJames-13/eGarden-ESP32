#ifndef DHTU_H
#define DHTU_H

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

class DHTSENSOR
{
public:
    DHTSENSOR(int pin, const uint8_t type);
    void begin();
    float getHumidity();
    float getTemperature();
    float getFarenheit();
    // float getHeatIndex();
    // float getFarenheitIndex();

    bool isHot(float temperatureThreshold);

private:
    DHT_Unified dht;
    int pin;
    const uint8_t type;
    float celsius;
    float farenheit;
    float humidity;
};

#endif
