#include "database_api.h"

DatabaseApi::DatabaseApi() {}
void DatabaseApi::begin(const String &serverUrl)
{
    this->serverUrl = serverUrl;
}

void DatabaseApi::insertData(const String &data, const String &table)
{
    HTTPClient http;
    http.begin(serverUrl + "/insert/" + table);
}

String DatabaseApi::getData(const String &table)
{
    HTTPClient http;
    String response;
    http.begin(serverUrl + "/get/" + table);
    int httpResponseCode = http.GET();
    if (httpResponseCode > 0)
    {
        response = http.getString();
        Serial.println(response);
    }
    http.end();
    return response;
}

void DatabaseApi::updateData(const String &data, const String &table)
{
    HTTPClient http;
    http.begin(serverUrl + "/update/" + table);
    http.addHeader("Content-Type", "application/json");
    int httpResponseCode = http.PUT(data);
    http.end();
}

void DatabaseApi::deleteData(const String &data, const String &table)
{
    HTTPClient http;
    http.begin(serverUrl + "/delete/" + table);
    http.addHeader("Content-Type", "application/json");
    int httpResponseCode = http.sendRequest("DELETE", data);
    http.end();
}
