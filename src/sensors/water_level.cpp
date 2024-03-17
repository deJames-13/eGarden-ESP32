#include <Arduino.h>
#include "water_level.h"

WaterLevel::WaterLevel() {}

void WaterLevel::begin()
{
    pinMode(WATER_LEVEL_PIN, INPUT);
}

WaterLevel::Level WaterLevel::getWaterLevel()
{
    int sensorValue = analogRead(WATER_LEVEL_PIN);

    if (sensorValue >= HIGH_THRESHOLD)
    {
        return Level::HIGH_LEVEL;
    }
    else if (sensorValue >= MEDIUM_THRESHOLD)
    {
        return Level::MEDIUM_LEVEL;
    }
    else
    {
        return Level::LOW_LEVEL;
    }
}

int WaterLevel::getSensorValue()
{
    return analogRead(WATER_LEVEL_PIN);
}
