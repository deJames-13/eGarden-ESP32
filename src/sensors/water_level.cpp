#include <Arduino.h>
#include "water_level.h"

WaterLevel::WaterLevel() {}

void WaterLevel::begin()
{
    pinMode(WATER_LEVEL_PIN, INPUT);
}

String WaterLevel::getWaterLevel()
{
    int sensorValue = analogRead(WATER_LEVEL_PIN);

    if (sensorValue >= HIGH_THRESHOLD)
    {
        return "High";
    }
    else if (sensorValue >= MEDIUM_THRESHOLD)
    {
        return "Medium";
    }
    else
    {
        return "Low";
    }
}

int WaterLevel::getSensorValue()
{
    return analogRead(WATER_LEVEL_PIN);
}
