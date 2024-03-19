#include "includes.h"

// WEB
OLED oledDisplay;
MyWebServer webServer;
NetworkManager networkManager; // FIXME: Network
DatabaseManager dbManager;     // FIXME: Database

// SENSORS
DHTSENSOR dhtSensor;
SoilMoisture soilSensor;
WaterLevel waterSensor;

// OUTPUT
Buzzer buzzer;
Fan fan1;
Fan fan2;
WaterValve valve;

// ACTIONS
void handleWatering(String waterLevel);
void handleFan();
void handleBuzzer();

// TESTS
void handleButtonClick();
int buttonPin = 4;
int buttonState = 0;

void setup()
{
    Serial.begin(4800);
    dhtSensor.begin();
    soilSensor.begin(SOIL_MOISTURE_PIN);
    waterSensor.begin(WATER_LEVEL_PIN);

    fan1.begin(RELAY_PIN_FAN1);
    fan2.begin(RELAY_PIN_FAN2);
    buzzer.begin(BUZZER_PIN);
    valve.begin(RELAY_PIN_VALVE);

    oledDisplay.begin(); // COMMENT OUT ON UR OWN RISK
    networkManager.connectToWiFi();
    webServer.begin();

    // TESTS
    pinMode(buttonPin, INPUT_PULLUP);
}

void loop()
{
    delay(500);
    // Serial.println("looping");

    // #########################################################
    // SENSOR INPUTS
    // #########################################################
    // FIXME: Test new DHT SENSOR
    // float temperature = dhtSensor.getTemperature();
    // float humidity = dhtSensor.getHumidity();
    // Serial.print("Temperature: ");
    // Serial.println(temperature);
    // Serial.print("Humidity: ");
    // Serial.println(humidity);
    // int moisture = soilSensor.getMoisture();
    // String waterLevel = waterSensor.getWaterLevel();
    // int waterValue = waterSensor.getSensorValue();
    // #########################################################

    // #########################################################
    // OLED INFO DISPLAY    FIXME: Adjsut Display
    // Update display with sensor data
    // #########################################################
    // oledDisplay.clearDisplay();
    // oledDisplay.displayTemperature(temperature);
    // oledDisplay.displayHumidity(humidity);
    // oledDisplay.displayMoisture(moisture);
    // oledDisplay.displayWaterStatus(waterLevel, waterValue);
    // oledDisplay.updateDisplay();

    // #########################################################
    // OUTPUT EVENTS
    // Update what will happen to output components: buzzer, fan, valve
    // #########################################################
    // handleBuzzer();
    // handleWatering(waterLevel);
    // handleFan(fan1);
    // #########################################################

    // #########################################################
    // WEB SERVER           FIXME: Test web server
    // Update sensor data on web server
    // #########################################################
    // webServer.updateSensorData(temperature, humidity, moisture, waterLevel, waterValue);
    // HANDLE CLIENT SERVER
    webServer.handleClient();
    // #########################################################

    // TESTING
    // handleButtonClick();
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

void handleFan(Fan fan)
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

void handleButtonClick()
{
    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH)
    {
        Serial.println("clicked");
        fan1.turnOn();
    }
    else
    {
        fan1.turnOff();
    }
}