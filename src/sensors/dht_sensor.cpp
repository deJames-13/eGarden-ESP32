// FIXME: Check code compatibility and errors
#include "dht_sensor.h"

DHTSENSOR::DHTSENSOR() : dht(DHT_PIN, DHT11) {}

void DHTSENSOR::begin()
{
    dht.begin();
}

float DHTSENSOR::getTemperature()
{
    return dht.readTemperature();
}
float DHTSENSOR::getHumidity()
{
    return dht.readHumidity();
}

// float DHTSENSOR::getTemperature_old()
// {
//     sensors_event_t event;
//     dhtu.temperature().getEvent(&event);
//     if (isnan(event.temperature))
//     {
//         return NAN;
//     }
//     else
//     {
//         return event.temperature;
//     }
// }
// float DHTSENSOR::getHumidity_old()
// {
//     sensors_event_t event;
//     dhtu.humidity().getEvent(&event);
//     if (isnan(event.relative_humidity))
//     {
//         return NAN;
//     }
//     else
//     {
//         return event.relative_humidity;
//     }
// }

bool DHTSENSOR::isHot(float temperatureThreshold)
{
    float temperature = getTemperature();
    return (temperature > temperatureThreshold);
}