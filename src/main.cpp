#include "includes.h"

OLED oledDisplay;
MyWebServer webServer;

// FIXME: Network
NetworkManager networkManager;

// FIXME: Database
DatabaseManager dbManager;

// SENSORS
DHT22SENSOR dhtSensor;
SoilMoisture soilSensor;
WaterLevel waterSensor;

// OUTPUT
Buzzer buzzer;
Fan fan;
WaterValve valve;
void handleWatering(String waterLevel);
void handleFan();
void handleBuzzer();

void setup()
{
    Serial.begin(9600);

    dhtSensor.begin();
    soilSensor.begin();
    waterSensor.begin();

    buzzer.begin();
    fan.begin();
    valve.begin();

    oledDisplay.begin();
    networkManager.connectToWiFi();
    webServer.begin();
}

void loop()
{
    // #########################################################
    // SENSOR INPUTS        FIXME: Test sensor inputs
    // #########################################################
    float temperature = dhtSensor.getTemperature();
    float humidity = dhtSensor.getHumidity();
    int moisture = soilSensor.getMoisture();
    String waterLevel = waterSensor.getWaterLevel();
    int waterValue = waterSensor.getSensorValue();
    // #########################################################

    // #########################################################
    // WEB SERVER           FIXME: Test web server
    // Update sensor data on web server
    // #########################################################
    webServer.updateSensorData(temperature, humidity, moisture, waterLevel, waterValue);
    // #########################################################

    // #########################################################
    // OlED INFO DISPLAY    FIXME: Test OLED display
    // Update display with sensor data
    // #########################################################
    oledDisplay.clearDisplay();
    oledDisplay.displayTemperature(temperature);
    oledDisplay.displayHumidity(humidity);
    oledDisplay.displayMoisture(moisture);
    oledDisplay.displayWaterStatus(waterLevel, waterValue);
    oledDisplay.updateDisplay();

    // #########################################################
    // OUTPUT EVENTS        FIXME: TEST EVENTS ON ACTUAL HARDWARE
    // Update what will happen to output components: buzzer, fan, valve
    // #########################################################
    handleWatering(waterLevel);
    handleFan();
    handleBuzzer();
    // #########################################################

    // HANDLE CLIENT SERVER
    webServer.handleClient();
    delay(1000);
}

// #########################################################
// ACTION EVENTS
// #########################################################

void handleWatering(String waterLevel)
{
    // FIXME: TEST LOGIC
    if (soilSensor.isTooDry() && waterLevel != "LOW")
    {
        valve.open();
    }
    else if (soilSensor.isTooWet())
    {
        valve.close();
    }
}

void handleFan()
{
    // FIXME: TEST LOGIC
    const float temperatureThreshold = 30;
    if (dhtSensor.isHot(temperatureThreshold))
    {
        fan.turnOn();
    }
    else
    {
        fan.turnOff();
    }
}

void handleBuzzer()
{
    // FIXME: TEST LOGIC
    if (waterSensor.isEmptyOrLow())
    {
        buzzer.buzzOnce();
        buzzer.setBuzzState(true);
    }
    else
    {
        buzzer.setBuzzState(false);
    }
}
