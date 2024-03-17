// fan.cpp
#include "fans.h"
#include "pin_config.h"
#include <Arduino.h>

Fan::Fan() {}

void Fan::begin()
{
    pinMode(RELAY_PIN_FAN, OUTPUT);
    digitalWrite(RELAY_PIN_FAN, LOW); // initially off
}

void Fan::turnOn()
{
    digitalWrite(RELAY_PIN_FAN, HIGH);
}

void Fan::turnOff()
{
    digitalWrite(RELAY_PIN_FAN, LOW);
}
