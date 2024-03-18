// buzzer.cpp
#include "buzzer.h"
#include "pin_config.h"
#include <Arduino.h>

Buzzer::Buzzer() {}

void Buzzer::begin()
{
    pinMode(BUZZER_PIN, OUTPUT);
    digitalWrite(BUZZER_PIN, LOW); // initially off
}

void Buzzer::buzzOnce()
{
    if (buzzed)
    {
        return;
    }

    digitalWrite(BUZZER_PIN, HIGH);
    delay(500); // FIXME: Adjust duration of buzz
    digitalWrite(BUZZER_PIN, LOW);
}

void Buzzer::setBuzzState(bool buzzState)
{
    buzzed = buzzState;
}