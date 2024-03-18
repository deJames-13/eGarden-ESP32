// FIXME: Check code compatibility and errors
#ifndef DHT22_H
#define DHT22_H

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include "pin_config.h"

class DHTSENSOR
{
public:
    DHTSENSOR();
    void begin();
    float getTemperature();
    float getHumidity();

    float getTemperature_old();
    float getHumidity_old();
    bool isHot(float temperatureThreshold);

private:
    DHT dht;
    // DHT_Unified dhtu;
};

#endif
