// water_valve.cpp
#include "water_valve.h"
#include "pin_config.h"
#include <Arduino.h>

WaterValve::WaterValve() {}

void WaterValve::begin(int pin)
{
    this->pin = pin;
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
