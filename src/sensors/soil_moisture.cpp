// FIXME: Check code compatibility and errors
#include <Arduino.h>
#include "soil_moisture.h"

#define DRY_THRESHOLD 300
#define WET_THRESHOLD 700

SoilMoisture::SoilMoisture() {}

void SoilMoisture::begin()
{
    pinMode(SOIL_MOISTURE_PIN, INPUT);
}

int SoilMoisture::getMoisture()
{
    return analogRead(SOIL_MOISTURE_PIN);
}

bool SoilMoisture::isTooDry()
{
    int moisture = getMoisture();
    return moisture < DRY_THRESHOLD;
}

bool SoilMoisture::isTooWet()
{
    int moisture = getMoisture();
    return moisture > WET_THRESHOLD;
}
