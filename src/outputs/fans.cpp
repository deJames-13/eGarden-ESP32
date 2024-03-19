// fan.cpp
#include "fans.h"

Fan::Fan(int pin) : pin(pin) {}

void Fan::begin()
{
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW); // initially off
}

void Fan::turnOn()
{
    digitalWrite(pin, HIGH);
}

void Fan::turnOff()
{
    digitalWrite(pin, LOW);
}
