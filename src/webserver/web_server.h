#ifndef MYWEBSERVER_H
#define MYWEBSERVER_H

#include <WebServer.h>
#include <SPIFFS.h> // FILE SYSTEM ACCESS
#include <ArduinoJson.h>

class MyWebServer
{
public:
    MyWebServer();
    void begin();
    void handleClient();
    void updateSensorData(float temperature, float humidity, int moisture, bool waterPresent);

private:
    WebServer server;
    float temp;
    float hum;
    int moist;
    bool water;
    String generateHTML();
    String generateJSON();
    String readIndexFile(); // READ INDEX.HTML FILE
};

#endif
