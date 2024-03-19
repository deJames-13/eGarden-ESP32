// buzzer.h
#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>
class Buzzer
{
public:
    Buzzer(int pin);
    void begin();
    void buzzOnce();
    void setBuzzState(bool buzzState);

private:
    bool buzzed = false;
    int pin;
};

#endif // BUZZER_H
