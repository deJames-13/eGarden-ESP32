// water_valve.cpp
#include "water_valve.h"

WaterValve::WaterValve(int pin) : pin(pin) {}

void WaterValve::begin()
{
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW); // initially off
}

void WaterValve::open()
{
    digitalWrite(pin, HIGH);
}

void WaterValve::close()
{
    digitalWrite(pin, LOW);
}
