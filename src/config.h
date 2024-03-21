
#ifndef CONFIG_H
#define CONFIG_H

// ##########################################################################
// PIN CONFIGURATION
// ##########################################################################
// FIXME: Pin assignments
// SENSORS
#define DHTTYPE DHT11
#define DHT_PIN 13 // Digital pin connected to the DHT sensor --  Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 -- Pin 15 can work but DHT must be disconnected during program upload.

#define SOIL_MOISTURE_PIN 39
// Moisture Threshold values
#define DRY_THRESHOLD 2000
#define WET_THRESHOLD 1000

#define WATER_LEVEL_PIN 34
// Water Threshold values
#define LOW_THRESHOLD 100    // FIXME:  Adjust as needed
#define MEDIUM_THRESHOLD 300 // FIXME:  Adjust as needed
#define HIGH_THRESHOLD 600   // FIXME:  Adjust as needed

// OUTPUTS
#define OLED_SDA 21
#define OLED_SCL 22
#define BUZZER_PIN 19
#define RELAY_PIN_VALVE 25 // relay input 17
#define RELAY_PIN_FAN1 26  // relay input 18
#define RELAY_PIN_FAN2 27  // 5
// ##########################################################################

// ##########################################################################
// DB CONFIGURATION
// ##########################################################################
#include <IPAddress.h>
const IPAddress DB_HOST(127, 0, 0, 1); // FIXME: Change to HOST IP
#define DB_USER "root"
#define DB_PASSWORD
#define DB_PORT 3306
#define DB_NAME 'egarden_db'
// ##########################################################################

// ##########################################################################
// WIFI CONFIGURATION
// ##########################################################################
// Replace "YourSSID" and "YourPassword" with your actual Wi-Fi credentials
#define WIFI_SSID "sp"
#define WIFI_PASSWORD "percyfied13"
// ##########################################################################

#endif
