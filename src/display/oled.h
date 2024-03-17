#ifndef OLED_H
#define OLED_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "../sensors/water_level.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1       // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

class OLED
{
public:
    OLED();
    void begin();
    void clearDisplay();
    void updateDisplay();
    void displayTemperature(float temperature);
    void displayHumidity(float humidity);
    void displayMoisture(int moisture);
    void displayWaterStatus(WaterLevel::Level waterLevel, int sensorValue);

private:
    Adafruit_SSD1306 display;
};

#endif
