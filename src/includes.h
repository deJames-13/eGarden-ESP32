#ifndef INCLUDES_H
#define INCLUDES_H

// CONFIG FILES
#include "pin_config.h"
#include "db_config.h"
#include "wifi_config.h"

// Include necessary libraries
#include <Arduino.h>
#include <SPI.h>
#include <WiFi.h>

// SENSORS
#include "sensors/dhtu_sensor.h" // new
#include "sensors/soil_moisture.h"
#include "sensors/water_level.h"

// OUTPUTS
#include "outputs/buzzer.h"
#include "outputs/fans.h"
#include "outputs/water_valve.h"

// DISPLAY
#include "display/oled.h"

// WEB SERVICE
#include "webserver/web_server.h"
#include "webserver/network_manager.h"
#include "webserver/database_manager.h"

#endif
