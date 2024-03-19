#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>
#include <WiFi.h>
#include <ArduinoJson.h>
#include <vector>
#include <map>
#include <string>

class DatabaseManager
{
public:
    DatabaseManager();
    ~DatabaseManager();
    void config(IPAddress host, char *user, int port, char *password, char *database);
    bool connect();
    void disconnect();
    void insertQuery(String query);
    String selectQuery(String query);

private:
    MySQL_Connection *conn = nullptr;
    WiFiClient client;
    IPAddress dbhost;
    int dbport;
    char *dbuser;
    char *dbpassword;
    char *dbname;
};

#endif // DATABASE_MANAGER_H
