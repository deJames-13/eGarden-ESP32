// FIXME: Check code compatibility and errors
#ifndef DHT22_H
#define DHT22_H

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include "pin_config.h"

class DHT22SENSOR
{
public:
    DHT22SENSOR();
    void begin();
    float getTemperature();
    float getHumidity();
    bool isHot(float temperatureThreshold);

private:
    DHT_Unified dht;
};

#endif
