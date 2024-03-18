// FIXME: Check code compatibility and errors
#include "dht22.h"

DHT22SENSOR::DHT22SENSOR() : dht(DHT_PIN, DHT22) {}

void DHT22SENSOR::begin()
{
    dht.begin();
}

float DHT22SENSOR::getTemperature()
{
    return dht.readTemperature();
}
float DHT22SENSOR::getHumidity()
{
    return dht.readHumidity();
}

// float DHT22SENSOR::getTemperature_old()
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
// float DHT22SENSOR::getHumidity_old()
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

bool DHT22SENSOR::isHot(float temperatureThreshold)
{
    float temperature = getTemperature();
    return (temperature > temperatureThreshold);
}