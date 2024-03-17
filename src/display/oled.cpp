#include "oled.h"

OLED::OLED() : display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET) {}

void OLED::begin()
{
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
    {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;)
            ;
    }
    display.clearDisplay();
}

void OLED::clearDisplay()
{
    display.clearDisplay();
}

void OLED::updateDisplay()
{
    display.display();
}

void OLED::displayTemperature(float temperature)
{
    display.setCursor(0, 0);
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.println("Temperature:");
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.println(temperature, 1);
}

void OLED::displayHumidity(float humidity)
{
    display.setCursor(0, 20);
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.println("Humidity:");
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.println(humidity, 1);
}

void OLED::displayMoisture(int moisture)
{
    display.setCursor(0, 40);
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.println("Moisture:");
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.println(moisture);
}

void OLED::displayWaterStatus(WaterLevel::Level waterLevel, int sensorValue)
{
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("Water Level:");

    display.setTextSize(2);

    switch (waterLevel)
    {
    case WaterLevel::HIGH_LEVEL:
        display.setTextColor(SSD1306_WHITE);
        display.println("High");
        break;
    case WaterLevel::MEDIUM_LEVEL:
        display.setTextColor(SSD1306_WHITE);
        display.println("Medium");
        break;
    case WaterLevel::LOW_LEVEL:
        display.setTextColor(SSD1306_WHITE);
        display.println("Low");
        break;
    default:
        display.setTextColor(SSD1306_WHITE);
        display.println("Unknown");
        break;
    }

    // Display sensor value
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 40);
    display.print("Sensor Value: ");
    display.println(sensorValue);

    display.display();
}
