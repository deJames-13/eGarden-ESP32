#ifndef WATER_LEVEL_H
#define WATER_LEVEL_H

#define WATER_LEVEL_PIN 4 // FIXME: Change PIN

class WaterLevel
{
public:
    enum Level
    {
        LOW_LEVEL,
        MEDIUM_LEVEL,
        HIGH_LEVEL
    };

    WaterLevel();
    void begin();
    String getWaterLevel();
    int getSensorValue();
};

// Threshold values
#define LOW_THRESHOLD 100    // FIXME:  Adjust as needed
#define MEDIUM_THRESHOLD 300 // FIXME:  Adjust as needed
#define HIGH_THRESHOLD 600   // FIXME:  Adjust as needed

#endif
