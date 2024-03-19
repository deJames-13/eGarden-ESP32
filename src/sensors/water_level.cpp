// FIXME: Check code compatibility and errors
#include <Arduino.h>
#include "water_level.h"

WaterLevel::WaterLevel(int pin) : pin(pin) {}

void WaterLevel::begin()
{
    pinMode(pin, INPUT);
}

String WaterLevel::getWaterLevel()
{
    return waterLevel;
}

int WaterLevel::getSensorValue()
{
    int val = analogRead(pin);
    if (val >= HIGH_THRESHOLD)
    {
        waterLevel = "High";
    }
    else if (val >= MEDIUM_THRESHOLD)
    {
        waterLevel = "Medium";
    }
    else
    {
        waterLevel = "Low";
    }
    return val;
}

bool WaterLevel::isEmptyOrLow()
{
    String waterLevel = getWaterLevel();
    if (waterLevel == "Low" || waterLevel == "Empty")
    {
        return true;
    }
    return false;
}