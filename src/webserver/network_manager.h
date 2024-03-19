// network_manager.h
#ifndef NETWORK_MANAGER_H
#define NETWORK_MANAGER_H

#include <Arduino.h>
#include <WiFi.h>
class NetworkManager
{
public:
    NetworkManager();
    bool connectToWiFi(String ssid, String password);
};

#endif // NETWORK_MANAGER_H
