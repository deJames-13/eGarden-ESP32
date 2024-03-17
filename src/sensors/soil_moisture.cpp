// FIXME: Check code compatibility and errors
#include <Arduino.h>
#include "soil_moisture.h"

SoilMoisture::SoilMoisture() {}

void SoilMoisture::begin()
{
    pinMode(SOIL_MOISTURE_PIN, INPUT);
}

int SoilMoisture::getMoisture()
{
    return analogRead(SOIL_MOISTURE_PIN);
}
