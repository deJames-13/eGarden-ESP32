#ifndef DHTU_H
#define DHTU_H

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#include "pin_config.h"

class DHTSENSOR
{
public:
    DHTSENSOR();
    void begin();
    float getHumidity();
    float getTemperature();
    float getFarenheit();
    // float getHeatIndex();
    // float getFarenheitIndex();

    bool isHot(float temperatureThreshold);

private:
    DHT_Unified dht;
    float celsius;
    float farenheit;
    float humidity;
};

#endif
