
#ifndef PIN_CONFIG_H
#define PIN_CONFIG_H

// FIXME: Pin assignments
// SENSORS
#define DHTTYPE DHT11
#define DHT_PIN 13 // Digital pin connected to the DHT sensor
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.

#define SOIL_MOISTURE_PIN 39
#define WATER_LEVEL_PIN 34

// OUTPUTS
#define OLED_SDA 21
#define OLED_SCL 22
#define BUZZER_PIN 19
#define RELAY_PIN_VALVE 25 // relay input 17
#define RELAY_PIN_FAN1 26  // relay input 18
#define RELAY_PIN_FAN2 27  // 5

#endif
