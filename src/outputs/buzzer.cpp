// buzzer.cpp
#include "buzzer.h"
#include "pin_config.h"
#include <Arduino.h>

Buzzer::Buzzer() {}

void Buzzer::begin(int pin)
{
    this->pin = pin;
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW); // initially off
}

void Buzzer::buzzOnce()
{
    if (buzzed)
    {
        return;
    }

    digitalWrite(pin, HIGH);
    delay(500); // FIXME: Adjust duration of buzz
    digitalWrite(pin, LOW);
}

void Buzzer::setBuzzState(bool buzzState)
{
    buzzed = buzzState;
}