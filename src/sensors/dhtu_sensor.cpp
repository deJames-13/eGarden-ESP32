#include "dhtu_sensor.h"

DHTSENSOR::DHTSENSOR() : dht(DHT_PIN, DHT11) {}

void DHTSENSOR::begin()
{
    dht.begin();
}
float DHTSENSOR::getHumidity()
{
    sensors_event_t event;
    dht.temperature().getEvent(&event);
    if (isnan(event.relative_humidity))
    {
        return NAN;
    }
    humidity = event.relative_humidity;
    return event.relative_humidity;
}
float DHTSENSOR::getTemperature()
{
    sensors_event_t event;
    dht.temperature().getEvent(&event);
    if (isnan(event.temperature))
    {
        return NAN;
    }
    celsius = event.temperature;
    return celsius;
}
float DHTSENSOR::getFarenheit()
{
    sensors_event_t event;
    dht.temperature().getEvent(&event);
    if (isnan(event.temperature))
    {
        return NAN;
    }
    farenheit = (event.temperature * 9 / 5) + 32;
    return farenheit;
}

bool DHTSENSOR::isHot(float temperatureThreshold)
{
    return (celsius > temperatureThreshold);
}