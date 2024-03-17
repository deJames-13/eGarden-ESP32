// network_manager.cpp
#include "network_manager.h"
#include <Arduino.h>
#include <WiFi.h>
#include "wifi_config.h"

NetworkManager::NetworkManager() {}

void NetworkManager::connectToWiFi()
{
    Serial.println("Connecting to Wi-Fi...");

    // Wifi credentials from wifi config header
    String ssid = String(WIFI_SSID);
    String password = String(WIFI_PASSWORD);

    // Connect to Wi-Fi
    WiFi.begin(ssid.c_str(), password.c_str());
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.println("Connecting to Wi-Fi...");
    }

    Serial.println("Connected to Wi-Fi");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
}
