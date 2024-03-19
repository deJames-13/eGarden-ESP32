// FIXME: TEST OUTPUT
// network_manager.cpp
#include "network_manager.h"

NetworkManager::NetworkManager() {}

bool NetworkManager::connectToWiFi(String ssid, String password)
{
    Serial.println("Connecting to Wi-Fi...");

    unsigned long startTime = millis();
    WiFi.begin(ssid.c_str(), password.c_str());
    while (WiFi.status() != WL_CONNECTED)
    {
        if (millis() - startTime > 5000)
        {
            Serial.println("Failed to connect to Wi-Fi");
            return false;
        }
        delay(1000);
        Serial.println("Connecting to Wi-Fi...");
    }

    Serial.println("Connected to Wi-Fi");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    return true;
}
