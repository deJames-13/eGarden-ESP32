#ifndef MYWEBSERVER_H
#define MYWEBSERVER_H

#include <ESPAsyncWebServer.h> // ASYNC WEB SERVER
#include <AsyncTCP.h>          // ASYNC TCP

#include <SPIFFS.h> // FILE SYSTEM ACCESS
#include <ArduinoJson.h>

class MyWebServer
{
public:
    MyWebServer();
    void begin();
    void handleClient();
    void updateSensorData(float temperature, float humidity, int moisture, const String &waterLevelStr, int waterLevelValue);

private:
    AsyncWebServer server;
    String htmlContent;
    float temp;
    float hum;
    int moist;
    int water;
    String waterLevel;
    String generateHTML();
    String generateJSON();
    String readIndexFile(const String &path); // READ INDEX.HTML FILE
};

#endif
