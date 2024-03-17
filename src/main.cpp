#include "includes.h"

DHT22SENSOR dhtSensor;
SoilMoisture soilSensor;
WaterLevel waterSensor;
OLED oledDisplay;
MyWebServer webServer;

void setup()
{
    Serial.begin(9600);

    dhtSensor.begin();
    soilSensor.begin();
    waterSensor.begin();
    oledDisplay.begin();
    webServer.begin();
}

void loop()
{
    // #########################################################
    // SENSOR INPUTS
    // #########################################################
    float temperature = dhtSensor.getTemperature();
    float humidity = dhtSensor.getHumidity();
    int moisture = soilSensor.getMoisture();
    bool waterPresent = waterSensor.isWaterPresent();
    // #########################################################

    // #########################################################
    // WEB SERVER
    // Update sensor data on web server
    // #########################################################
    webServer.updateSensorData(temperature, humidity, moisture, waterPresent);
    // #########################################################

    // #########################################################
    // OlED INFO
    // Update display
    // #########################################################
    oledDisplay.clearDisplay();
    oledDisplay.displayTemperature(temperature);
    oledDisplay.displayHumidity(humidity);
    oledDisplay.displayMoisture(moisture);
    oledDisplay.displayWaterStatus(waterPresent);
    oledDisplay.updateDisplay();

    // HANDLE CLIENT SERVER
    webServer.handleClient();
    delay(1000);
}
