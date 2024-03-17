// buzzer.cpp
#include "buzzer.h"
#include "pin_config.h"
#include <Arduino.h>

void Buzzer::begin()
{
    pinMode(BUZZER_PIN, OUTPUT);
    digitalWrite(BUZZER_PIN, LOW); // initially off
}

void Buzzer::buzzOnce()
{
    digitalWrite(BUZZER_PIN, HIGH);
    delay(100); // FIXME: Adjust duration of buzz
    digitalWrite(BUZZER_PIN, LOW);
}
