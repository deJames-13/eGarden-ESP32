// FIXME: Check code compatibility and errors
#include <Arduino.h>
#include "soil_moisture.h"

#define DRY_THRESHOLD 2000
#define WET_THRESHOLD 1000

SoilMoisture::SoilMoisture(int pin) : pin(pin) {}

void SoilMoisture::begin()
{
    pinMode(pin, INPUT);
}

int SoilMoisture::getMoisture()
{
    moisture = analogRead(pin);
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
