// fan.cpp
#include "fans.h"

Fan::Fan() {}

void Fan::begin(int pin)
{
    this->pin = pin;
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
