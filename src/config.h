
#ifndef CONFIG_H
#define CONFIG_H

// ##########################################################################
// PIN CONFIGURATION
// ##########################################################################
// FIXME: Pin assignments
// Digital pin connected to the DHT sensor --  Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 -- Pin 15 can work but DHT must be disconnected during program upload.

// OCCUPIED ESP32 PINS
// WIFI GPIO 2 - TOUCH2 ADC12
// WIFI GPIO 14 - TOUCH6 ADC16
// WIFI GPIO 27 - TOUCH7 ADC17
// OLED GPIO 21 - SDA
// OLED GPIO 22 - SCL
// RX GPIO 3 - U0R
// TX GPIO 1 - U0T
// INPUT ONLY PINS
// GPIO 36
// GPIO 39
// GPIO 34
// GPIO 35

// SENSORS
#define DHTTYPE DHT11
#define DHT_PIN 13
#define SOIL_MOISTURE_PIN 36
#define WATER_LEVEL_PIN 39
// OUTPUTS
#define OLED_SDA 21        // GPIO 21 - SDA
#define OLED_SCL 22        // GPIO 22 - SCL
#define BUZZER_PIN 32      // GPIO 32 - TOUCH9 ADC10
#define RELAY_PIN_VALVE 33 // GPIO 33 - TOUCH8 ADC11
#define RELAY_PIN_FAN1 25  // GPIO 25 - DAC1
#define RELAY_PIN_FAN2 26  // GPIO 26 - DAC1

// Moisture Threshold values
#define DRY_THRESHOLD 2000 // FIXME:  Adjust as needed
#define WET_THRESHOLD 1000 // FIXME:  Adjust as needed
// Water Threshold values
#define LOW_THRESHOLD 100    // FIXME:  Adjust as needed
#define MEDIUM_THRESHOLD 300 // FIXME:  Adjust as needed
#define HIGH_THRESHOLD 600   // FIXME:  Adjust as needed
// ##########################################################################

// ##########################################################################
// DB CONFIGURATION
// ##########################################################################
// #include <IPAddress.h>
// const IPAddress DB_HOST(127, 0, 0, 1); // FIXME: Change to HOST IP
// #define DB_USER "root"
// #define DB_PASSWORD
// #define DB_PORT 3306
// #define DB_NAME 'egarden_db'
// ##########################################################################

// ##########################################################################
// WIFI CONFIGURATION
// ##########################################################################
// Replace "YourSSID" and "YourPassword" with your actual Wi-Fi credentials
#define WIFI_SSID "sp"
#define WIFI_PASSWORD "percyfied13"
// ##########################################################################

#endif
