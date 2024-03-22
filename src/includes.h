#ifndef INCLUDES_H
#define INCLUDES_H

// CONFIG FILES
#include "config.h"

// Include necessary libraries
#include <Arduino.h>
#include <SPI.h>
#include <WiFi.h>

// SENSORS
#include "sensors/dht_sensor.h"
#include "sensors/soil_moisture.h"
#include "sensors/water_level.h"

// OUTPUTS
#include "outputs/buzzer.h"
#include "outputs/fans.h"
#include "outputs/water_valve.h"

// DISPLAY
#include "display/oled.h"

// WEB SERVICE
#include "bluetooth/bluetooth_manager.h"
#include "webserver/web_server.h"
#include "webserver/network_manager.h"
#include "webserver/database_manager.h"

#endif
