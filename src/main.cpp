#include "includes.h"

// WEB
OLED myOled;
MyWebServer webServer;
NetworkManager networkManager; // FIXME: Network
DatabaseManager dbManager;     // FIXME: Database

// SENSORS
DHTSENSOR dhtSensor(DHT_PIN, DHTTYPE);
SoilMoisture soilSensor(SOIL_MOISTURE_PIN);
WaterLevel waterSensor(WATER_LEVEL_PIN, LOW_THRESHOLD, MEDIUM_THRESHOLD, HIGH_THRESHOLD);

// OUTPUT
Buzzer buzzer(BUZZER_PIN);
Fan fan1(RELAY_PIN_FAN1);
Fan fan2(RELAY_PIN_FAN2);
WaterValve valve(RELAY_PIN_VALVE);

// ACTIONS
void handleWatering(String waterLevel);
void handleFan(Fan fan);
void handleBuzzer();

// TESTS
void handleButtonClick();

// VARIABLES
float temperature = 0;
float humidity = 0;
int moisture = 0;
int waterValue = 0;
String waterLevel = "";

int buttonPin = 4;
int buttonState = 0;

void setup()
{
    // COMMENT OUT ON UR OWN RISK - Panic error if not began properly
    Serial.begin(9600);
    dhtSensor.begin();
    soilSensor.begin();
    waterSensor.begin();

    fan1.begin();
    fan2.begin();
    buzzer.begin();
    valve.begin();

    myOled.begin();
    networkManager.connectToWiFi(WIFI_SSID, WIFI_PASSWORD);
    webServer.begin();

    // TESTS
    // pinMode(buttonPin, INPUT_PULLUP);
}

void loop()
{
    delay(1000);
    // Serial.println("looping");

    // #########################################################
    // SENSOR INPUTS
    // #########################################################
    // FIXME: Test new DHT SENSOR
    temperature = dhtSensor.getTemperature();
    humidity = dhtSensor.getHumidity();
    moisture = soilSensor.getMoisture();
    waterValue = waterSensor.getSensorValue();
    waterLevel = waterSensor.getWaterLevel(waterValue);
    // #########################################################

    // #########################################################
    // OLED INFO DISPLAY    FIXME: Adjsut Display
    // Update display with sensor data
    // #########################################################
    myOled.displayDHT(dhtSensor);
    myOled.displayMoisture(soilSensor);
    myOled.displayWater(waterSensor);

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
    if (soilSensor.isTooDry(DRY_THRESHOLD) && waterLevel != "LOW")
    {
        valve.open();
    }
    else if (soilSensor.isTooWet(WET_THRESHOLD))
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