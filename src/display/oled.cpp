#include "oled.h"

OLED::OLED() : display(SCREEN_WIDTH, SCREEN_HEIGHT, &WIRE, OLED_RESET) {}

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
    display.print("Temperature:");
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.print(temperature, 1);
    display.println("°C");
}

void OLED::displayHumidity(float humidity)
{
    display.setCursor(0, 20);
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.print("Humidity:");
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.println(humidity, 1);
}

void OLED::displayMoisture(int moisture)
{
    display.setCursor(0, 40);
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.print("Moisture:");
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.println(moisture);
}

void OLED::displayWaterStatus(const String &waterLevel, int sensorValue)
{
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.print("Water Level:");
    display.setTextSize(2);
    display.println(waterLevel);

    // Display sensor value
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 40);
    display.print("Sensor Value: ");
    display.println(sensorValue);

    display.display();
}
