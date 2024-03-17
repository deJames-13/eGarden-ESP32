// FIXME: TEST OUTPUT
#include "web_server.h"

MyWebServer::MyWebServer() : server(80) {}

void MyWebServer::begin()
{
    server.begin();

    // MAIN
    server.on("/", HTTP_GET, [this]()
              { server.send(200, "text/html", generateHTML()); });
    // DATA JSON
    server.on("/data", HTTP_GET, [this]()
              { server.send(200, "application/json", generateJSON()); });
}

void MyWebServer::handleClient()
{
    server.handleClient();
}

void MyWebServer::updateSensorData(float temperature, float humidity, int moisture, const String &waterLevelStr, int waterLevelValue)
{
    temp = temperature;
    hum = humidity;
    moist = moisture;
    waterLevel = waterLevelStr;
    water = waterLevelValue;
}

String MyWebServer::generateHTML()
{
    String html = "<!DOCTYPE html><html><head><title>eGarden Dashboard</title></head><body>";
    html += "<h1>eGarden Dashboard</h1>";
    html += "<p>Temperature: " + String(temp) + "°C</p>";
    html += "<p>Humidity: " + String(hum) + "%</p>";
    html += "<p>Soil Moisture: " + String(moist) + "</p>";
    html += "<p>Water Value: " + String(water) + "</p>";
    html += "</body></html>";
    return html;
}
String MyWebServer::readIndexFile()
{
    File indexFile = SPIFFS.open("/index.html", "r");
    if (!indexFile)
    {
        Serial.println("Failed to open index.html file");
        return "";
    }
    String html = indexFile.readString();
    indexFile.close();
    return html;
}
String MyWebServer::generateJSON()
{
    JsonDocument doc;
    doc["temperature"] = temp;
    doc["humidity"] = hum;
    doc["moisture"] = moist;
    doc["waterLevel"] = waterLevel;
    doc["waterValue"] = water;

    String json;
    serializeJson(doc, json);
    return json;
}