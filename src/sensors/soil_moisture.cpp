// FIXME: Check code compatibility and errors
#include <Arduino.h>
#include "soil_moisture.h"

// TODO: add soil moisture threshold
// TODO: Soil Moisture Calibration
// SOIL IS DRY
// TODO: detect if soil moisture is too low and if the garden needs watering
// SOIL IS WET
// TODO: detect if soil moisture is too high and if the garden needs to be dried

SoilMoisture::SoilMoisture() {}

void SoilMoisture::begin()
{
    pinMode(SOIL_MOISTURE_PIN, INPUT);
}

int SoilMoisture::getMoisture()
{
    return analogRead(SOIL_MOISTURE_PIN);
}
