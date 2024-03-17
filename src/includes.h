#ifndef INCLUDES_H
#define INCLUDES_H

// Include necessary libraries
#include <Arduino.h>

// SENSORS
#include "sensors/dht22.h"
#include "sensors/soil_moisture.h"
#include "sensors/water_level.h"

// OUTPUTS
#include "outputs/buzzer.h"
#include "outputs/fans.h"
#include "outputs/water_valve.h"

#include "display/oled.h"
#include "webserver/web_server.h"

#endif
