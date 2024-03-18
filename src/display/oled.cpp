#include "oled.h"

OLED::OLED() : display(SCREEN_WIDTH, SCREEN_HEIGHT, &WIRE, OLED_RESET) {}

void OLED::begin()
{
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
    {
        Serial.println(F("SSD1306 allocation failed"));
    }
    display.clearDisplay();
}

void OLED::clearDisplay()
{
    display.setCursor(0, 0);
    display.clearDisplay();
}

void OLED::updateDisplay()
{
    display.display();
}

void OLED::displayTemperature(float temperature)
{
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    display.print("Temperature: ");
    display.print(temperature, 1);
    display.println("C");
}

void OLED::displayHumidity(float humidity)
{
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    display.print("Humidity: ");
    display.println(humidity, 1);
}

void OLED::displayMoisture(int moisture)
{
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    display.print("Moisture: ");
    display.print(moisture, 1);
    if (moisture > 2000)
    {
        display.println(" (Dry)");
    }
    else if (moisture < 1000)
    {
        display.println(" (Wet)");
    }
    else
    {
        display.println(" (Good)");
    }
}

void OLED::displayWaterStatus(const String &waterLevel, int sensorValue)
{

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.print("Water Value: ");
    display.print(sensorValue);
    display.print(" (");
    display.print(waterLevel);
    display.println(")");
}

void OLED::testPrint(String text)
{
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.print("Test:");
    display.println(text);
}