// FIXME: Check code compatibility and errors
#include <Arduino.h>
#include "soil_moisture.h"

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

bool SoilMoisture::isTooDry(int threshold)
{
    return moisture > threshold;
}

bool SoilMoisture::isTooWet(int threshold)
{
    return moisture < threshold;
}
