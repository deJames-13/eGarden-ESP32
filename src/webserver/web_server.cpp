// FIXME: TEST OUTPUT
#include "web_server.h"

MyWebServer::MyWebServer() : server(80) {}

void MyWebServer::begin()
{

    if (!SPIFFS.begin(true))
    {
        Serial.println("An error has occurred while mounting SPIFFS");
        return;
    }

    server.begin();
    // MAIN
    htmlContent = readIndexFile("/index.html");
    server.on("/", HTTP_GET, [this](AsyncWebServerRequest *request)
              { request->send(200, "text/html", this->htmlContent); });
    server.on("/index.js", HTTP_GET, [this](AsyncWebServerRequest *request)
              { request->send(200, "text/javascript", this->readIndexFile("/index.js")); });
    server.on("/plain-text", HTTP_GET, [this](AsyncWebServerRequest *request)
              { request->send(200, "text/html", this->generateHTML()); });
    server.on("/data", HTTP_GET, [this](AsyncWebServerRequest *request)
              { request->send(200, "application/json", this->generateJSON()); });
}

void MyWebServer::handleClient()
{
    // server.handleClient();
}

void MyWebServer::updateSensorData(float temperature, float humidity, int moisture, const String &waterLevelStr, int waterLevelValue)
{
    temp = temperature;
    hum = humidity;
    moist = moisture;
    waterLevel = waterLevelStr;
    water = waterLevelValue;
    htmlContent = readIndexFile("/index.html");
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

String MyWebServer::readIndexFile(const String &path)
{
    File file = SPIFFS.open(path);
    if (!file)
    {
        Serial.println("Failed to open file: " + path);
        return "";
    }
    String content = file.readString();
    file.close();
    content.replace("{temperature}", String(temp));
    content.replace("{humidity}", String(hum));
    content.replace("{moisture}", String(moist));
    content.replace("{waterLevelStr}", waterLevel);
    content.replace("{waterLevelValue}", String(water));
    return content;
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