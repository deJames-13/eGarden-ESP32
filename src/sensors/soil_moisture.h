#ifndef SOIL_MOISTURE_H
#define SOIL_MOISTURE_H

#include "pin_config.h"

class SoilMoisture
{
public:
    SoilMoisture();
    void begin();
    int getMoisture();
    bool isTooDry();
    bool isTooWet();
};

#endif
