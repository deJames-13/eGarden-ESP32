// water_valve.h
#ifndef WATER_VALVE_H
#define WATER_VALVE_H

#include <Arduino.h>
class WaterValve
{
public:
    WaterValve(int pin);
    void begin();
    void open();
    void close();

private:
    int pin;
};

#endif // WATER_VALVE_H
