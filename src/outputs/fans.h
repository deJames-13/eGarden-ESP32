// fan.h
#ifndef FAN_H
#define FAN_H

#include <Arduino.h>
class Fan
{
public:
    Fan();
    void begin(int pin);
    void turnOn();
    void turnOff();

private:
    int pin;
};

#endif // FAN_H
