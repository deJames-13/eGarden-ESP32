// network_manager.h
#ifndef NETWORK_MANAGER_H
#define NETWORK_MANAGER_H

#include <Arduino.h>
#include <WiFi.h>
#include "wifi_config.h"
class NetworkManager
{
public:
    NetworkManager();
    bool connectToWiFi();
};

#endif // NETWORK_MANAGER_H
