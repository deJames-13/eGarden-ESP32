#ifndef SOIL_MOISTURE_H
#define SOIL_MOISTURE_H

class SoilMoisture
{
public:
    SoilMoisture(int pin);
    void begin();
    int getMoisture();
    bool isTooDry(int threshold);
    bool isTooWet(int threshold);

private:
    int pin;
    int moisture;
};

#endif
