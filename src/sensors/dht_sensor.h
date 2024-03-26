// FIXME: Check code compatibility and errors
#ifndef DHT22_H
#define DHT22_H

#include <Adafruit_Sensor.h>
#include <DHT.h>

class DHTSENSOR
{
public:
    DHTSENSOR(int pin, const uint8_t type);
    void begin();
    float getHumidity();
    float getTemperature();
    float getFarenheit();
    float getHeatIndex();
    float getFarenheitIndex();
    bool isHot(float temperatureThreshold, float temp);

private:
    DHT dht;
    int pin;
    const uint8_t type;
    float temperature;
    float humidity;
    float farenheit;
    float heatIndex;
    float farenheitIndex;
};

#endif
