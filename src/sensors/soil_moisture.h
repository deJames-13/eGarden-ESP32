#ifndef SOIL_MOISTURE_H
#define SOIL_MOISTURE_H

#define SOIL_MOISTURE_PIN 23 // FIXME: Change Pin
class SoilMoisture
{
public:
    SoilMoisture();
    void begin();
    int getMoisture();
};

#endif
