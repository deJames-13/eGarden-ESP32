// buzzer.cpp
#include "buzzer.h"

Buzzer::Buzzer(int pin) : pin(pin) {}

void Buzzer::begin()
{
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