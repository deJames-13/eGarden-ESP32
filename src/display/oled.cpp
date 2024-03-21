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

void OLED::displayDHT(DHTSENSOR &dhtSensor)
{
    this->clearDisplay();
    display.setFont(&FreeMonoBold9pt7b);
    display.println("Temperature");
    display.println(String(dhtSensor.getTemperature()) + " C");
    this->updateDisplay();

    delay(3000);

    this->clearDisplay();
    display.setFont(&FreeMonoBold9pt7b);
    display.println("Humidity");
    display.println(String(dhtSensor.getHumidity()));
    this->updateDisplay();

    delay(3000);
}

void OLED::displayMoisture(SoilMoisture &soilSensor)
{
    this->clearDisplay();
    display.setFont(&FreeMonoBold9pt7b);
    display.println("Moisture");
    display.println(String(soilSensor.getMoisture()));
    this->updateDisplay();

    delay(3000);
}

void OLED::displayWater(WaterLevel &waterSensor)
{
    int val = waterSensor.getSensorValue();
    this->clearDisplay();
    display.setFont(&FreeMonoBold9pt7b);
    display.println("Water Value");
    display.println(String(val) + " (" + String(waterSensor.getWaterLevel(val)) + ")");
    this->updateDisplay();
    delay(3000);
}