#include "includes.h"

OLED oledDisplay;
MyWebServer webServer;

// FIXME: Network
NetworkManager networkManager;

// FIXME: Database
DatabaseManager dbManager;

// SENSORS
DHTSENSOR dhtSensor;
SoilMoisture soilSensor;
WaterLevel waterSensor;

// OUTPUT
Buzzer buzzer;
Fan fan;
WaterValve valve;
void handleWatering(String waterLevel);
void handleFan();
void handleBuzzer();

// TEST
#define LED 26

void setup()
{
    Serial.begin(9600);
    dhtSensor.begin();
    // soilSensor.begin();
    // waterSensor.begin();

    // buzzer.begin();
    // fan.begin();
    // valve.begin();

    oledDisplay.begin(); // COMMENT OUT ON UR OWN RISK
    networkManager.connectToWiFi();
    webServer.begin();
}

void loop()
{
    // #########################################################
    // SENSOR INPUTS
    // #########################################################
    float temperature = dhtSensor.getTemperature();
    Serial.print("Temp: ");
    Serial.println(temperature);
    // FIXME: Test new DHT SENSOR
    // float humidity = dhtSensor.getHumidity();
    // int moisture = soilSensor.getMoisture();
    // String waterLevel = waterSensor.getWaterLevel();
    // int waterValue = waterSensor.getSensorValue();
    // #########################################################

    // #########################################################
    // OLED INFO DISPLAY    FIXME: Adjsut Display
    // Update display with sensor data
    // #########################################################
    oledDisplay.clearDisplay();
    // oledDisplay.displayTemperature(temperature);
    // oledDisplay.displayHumidity(humidity);
    // oledDisplay.displayMoisture(moisture);
    // oledDisplay.displayWaterStatus(waterLevel, waterValue);
    oledDisplay.updateDisplay();

    // #########################################################
    // OUTPUT EVENTS
    // Update what will happen to output components: buzzer, fan, valve
    // #########################################################
    // handleBuzzer();
    // handleWatering(waterLevel);      FIXME: TEST EVENTS ON RELAY
    // handleFan();                     FIXME: TEST EVENTS ON RELAY
    // #########################################################

    // #########################################################
    // WEB SERVER           FIXME: Test web server
    // Update sensor data on web server
    // #########################################################
    // webServer.updateSensorData(temperature, humidity, moisture, waterLevel, waterValue);
    // HANDLE CLIENT SERVER
    webServer.handleClient();
    // #########################################################
    delay(500);
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
