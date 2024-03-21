#ifndef WATER_LEVEL_H
#define WATER_LEVEL_H

class WaterLevel
{
public:
    WaterLevel(int pin, int lowThreshold, int mediumThreshold, int highThreshold);
    void begin();
    int getSensorValue();
    String getWaterLevel(int value);
    bool isEmptyOrLow();

private:
    int pin;
    String waterLevel;
    int value;
    int lowThreshold = 100;
    int mediumThreshold = 300;
    int highThreshold = 600;
};

#endif
