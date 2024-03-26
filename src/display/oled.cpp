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
    display.clearDisplay();
    display.setCursor(0, 12);
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
}

void OLED::updateDisplay()
{
    display.display();
}

void OLED::displayText(String text)
{
    this->clearDisplay();
    display.println(text);
    this->updateDisplay();
}

void OLED::displayDHT(float temperature, int humidity)
{
    this->clearDisplay();
    display.setFont(&FreeMonoBold9pt7b);
    display.println("Temperature");
    display.println(String(temperature, 2) + " C");
    this->updateDisplay();

    delay(1500);

    this->clearDisplay();
    display.setFont(&FreeMonoBold9pt7b);
    display.println("Humidity");
    display.println(String(humidity));
    this->updateDisplay();

    delay(1500);
}

void OLED::displayMoisture(int moisture)
{
    this->clearDisplay();
    display.setFont(&FreeMonoBold9pt7b);
    display.println("Moisture");
    display.println(String(moisture));
    this->updateDisplay();

    delay(1500);
}

void OLED::displayWater(int waterValue, String waterLevel)
{
    this->clearDisplay();
    display.setFont(&FreeMonoBold9pt7b);
    display.println("Water Value");
    display.println(String(waterValue) + " (" + waterLevel + ")");
    this->updateDisplay();
    delay(1500);
}