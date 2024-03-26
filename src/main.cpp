#include "includes.h"

// WEB
MyWebServer webServer;
NetworkManager networkManager;
BluetoothManager myBluetooth("ESPBluetooth");

// SENSORS
DHTSENSOR dhtSensor(DHT_PIN, DHTTYPE);
SoilMoisture soilSensor(SOIL_MOISTURE_PIN);
WaterLevel waterSensor(WATER_LEVEL_PIN, LOW_THRESHOLD, MEDIUM_THRESHOLD, HIGH_THRESHOLD);

// OUTPUT
OLED myOled;
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

int buttonPin = 32;
int buttonState = 0;

void printSensorData();

void setup()
{
    // COMMENT OUT ON UR OWN RISK - Panic error if not began properly
    Serial.begin(9600);
    dhtSensor.begin();
    soilSensor.begin();
    waterSensor.begin();

    pinMode(RELAY_PIN_FAN1, OUTPUT);
    // fan1.begin();
    fan2.begin();
    buzzer.begin();
    valve.begin();

    myOled.begin();
    networkManager.connectToWiFi(WIFI_SSID, WIFI_PASSWORD);
    webServer.begin();
    myBluetooth.begin();

    // TESTS
    pinMode(buttonPin, INPUT_PULLUP);
}

void loop()
{
    delay(2000);
    Serial.print("Fan: ");
    digitalWrite(RELAY_PIN_FAN1, LOW);
    Serial.println(digitalRead(RELAY_PIN_FAN1));

    delay(2000);
    Serial.print("Fan: ");
    digitalWrite(RELAY_PIN_FAN1, HIGH);
    Serial.println(digitalRead(RELAY_PIN_FAN1));

    // #########################################################
    // SENSOR INPUTS
    // #########################################################
    // FIXME: Test new DHT SENSOR
    // temperature = dhtSensor.getTemperature();
    // humidity = dhtSensor.getHumidity();
    // moisture = soilSensor.getMoisture();
    // waterValue = waterSensor.getSensorValue();
    // waterLevel = waterSensor.getWaterLevel(waterValue);
    // #########################################################

    // #########################################################
    // WEB SERVER           FIXME: Test web server
    // Update sensor data on web server
    // #########################################################
    // webServer.updateSensorData(temperature, humidity, moisture, waterLevel, waterValue);
    // HANDLE CLIENT SERVER
    // webServer.handleClient();
    // #########################################################

    // #########################################################
    // OLED INFO DISPLAY    FIXME: Adjsut Display
    // Update display with sensor data
    // #########################################################
    // printSensorData();
    // myOled.displayDHT(temperature, humidity);
    // myOled.displayMoisture(moisture);
    // myOled.displayWater(waterValue, waterLevel);

    // #########################################################
    // OUTPUT EVENTS
    // Update what will happen to output components: buzzer, fan, valve
    // #########################################################
    // handleBuzzer();
    // handleWatering(waterLevel);
    // handleFan(fan1);
    // handleFan(fan2);
    // handleBluetooth();

    // #########################################################
}

// #########################################################
// ACTION EVENTS
// #########################################################

void handleWatering(String waterLevel)
{
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
    const float temperatureThreshold = 35;
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
    }
    else
    {
    }
}

// #########################################################
// SERIAL PRINT
// #########################################################
void printSensorData()
{

    Serial.println("\n\n#########################################################");
    Serial.println("SENSOR DATA:");
    Serial.println("#########################################################");
    Serial.println("Temperature: \t\t" + String(temperature) + "°C");
    Serial.println("Humidity: \t\t" + String(humidity) + "%");
    Serial.println("Soil Moisture: \t\t" + String(moisture));
    Serial.println("Water Value: \t\t" + String(waterValue));
    Serial.println("Water Level: \t\t" + waterLevel);
    Serial.println("#########################################################");
    Serial.println();
}

// #########################################################
// BLUETOOTH COMMANDS
// #########################################################
void handleBluetooth()
{
    String command = myBluetooth.getCommand();
    if (command != "")
    {
        Serial.println("BLuetoothCommand: " + command);
        if (command == "water_on")
        {
            valve.open();
        }
        else if (command == "water_off")
        {
            valve.close();
        }
        else if (command == "fan_on")
        {
            fan1.turnOn();
        }
        else if (command == "fan_off")
        {
            fan1.turnOff();
        }
        else if (command == "buzzer_on")
        {
            buzzer.buzzOnce();
        }
    }
}