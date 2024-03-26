// FIXME: Check code compatibility and errors
#include "dht_sensor.h"

DHTSENSOR::DHTSENSOR(int pin, const uint8_t type) : pin(pin), type(type), dht(pin, type) {}

void DHTSENSOR::begin()
{
    dht.begin();
}

float DHTSENSOR::getTemperature()
{
    temperature = dht.readTemperature();
    return temperature;
}
float DHTSENSOR::getHumidity()
{
    humidity = dht.readHumidity();
    return humidity;
}

float DHTSENSOR::getFarenheit()
{
    farenheit = dht.readTemperature(true);
    return farenheit;
}

float DHTSENSOR::getHeatIndex()
{
    return dht.computeHeatIndex(temperature, humidity, false);
}

float DHTSENSOR::getFarenheitIndex()
{
    return dht.computeHeatIndex(farenheit, humidity, false);
}

bool DHTSENSOR::isHot(float temperatureThreshold, float temp)
{
    if (temp > temperatureThreshold)
    {
        return true;
    }
    return false;
}