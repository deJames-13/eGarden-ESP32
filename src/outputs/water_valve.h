// water_valve.h
#ifndef WATER_VALVE_H
#define WATER_VALVE_H

class WaterValve
{
public:
    WaterValve();
    void begin(int pin);
    void open();
    void close();

private:
    int pin;
};

#endif // WATER_VALVE_H
