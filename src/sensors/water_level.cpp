#include <Arduino.h>
#include "water_level.h"

WaterLevel::WaterLevel(int pin, int lowThreshold, int mediumThreshold, int highThreshold)
{
    this->pin = pin;
    this->lowThreshold = lowThreshold;
    this->mediumThreshold = mediumThreshold;
    this->highThreshold = highThreshold;
}

void WaterLevel::begin()
{
    pinMode(pin, INPUT);
}

String WaterLevel::getWaterLevel(int value)
{
    if (value >= highThreshold)
    {
        waterLevel = "HIGH";
    }
    else if (value >= mediumThreshold)
    {
        waterLevel = "MEDIUM";
    }
    else if (value > 0)
    {
        waterLevel = "LOW";
    }
    else
    {
        waterLevel = "EMPTY";
    }
    return waterLevel;
}

int WaterLevel::getSensorValue()
{
    value = analogRead(pin);
    return value;
}

bool WaterLevel::isEmptyOrLow()
{
    String waterLevel = getWaterLevel(value);
    if (waterLevel == "LOW" || waterLevel == "EMPTY")
    {
        return true;
    }
    return false;
}