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
