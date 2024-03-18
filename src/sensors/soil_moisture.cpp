// FIXME: Check code compatibility and errors
#include <Arduino.h>
#include "soil_moisture.h"

#define DRY_THRESHOLD 2000
#define WET_THRESHOLD 1000

SoilMoisture::SoilMoisture() {}

void SoilMoisture::begin()
{
    pinMode(SOIL_MOISTURE_PIN, INPUT);
}

int SoilMoisture::getMoisture()
{
    moisture = analogRead(SOIL_MOISTURE_PIN);
    moisture = map(moisture, 0, 4095, 0, 3000);
    return moisture;
}

bool SoilMoisture::isTooDry()
{
    return moisture > DRY_THRESHOLD;
}

bool SoilMoisture::isTooWet()
{
    return moisture < WET_THRESHOLD;
}
