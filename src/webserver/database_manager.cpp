// TODO: Configure functions
// FIXME: TEST OUTPUT
#include "database_manager.h"

NetworkManager nm;
DatabaseManager::DatabaseManager()
{
    conn = new MySQL_Connection((Client *)&client);
}
DatabaseManager::~DatabaseManager()
{
    if (conn != nullptr)
    {
        conn->close();
        delete conn;
    }
}

void DatabaseManager::config(IPAddress host, char *user, int port, char *password, char *database)
{
    dbhost = host;
    dbuser = user;
    dbport = port;
    dbpassword = password;
    dbname = database;
}

bool DatabaseManager::connect()
{
    if (WiFi.status() == WL_CONNECTED || nm.connectToWiFi())
    {
        if (conn->connect(dbhost, dbport, dbuser, dbpassword, dbname))
        {
            Serial.println("Connected to MySQL server");
            return true;
        }
        else
        {
            Serial.println("Connection failed.");
        }
    }
    else
    {
        Serial.println("Not connected to Wi-Fi");
    }
    return false;
}

void DatabaseManager::disconnect()
{
    if (conn != nullptr)
    {
        conn->close();
    }
}

void DatabaseManager::insertQuery(String query)
{
    if (!connect())
    {
        Serial.println("Connection failed");
        return;
    }

    MySQL_Cursor *cur_mem = new MySQL_Cursor(conn);
    cur_mem->execute(query.c_str());
    delete cur_mem;
    disconnect();
}

std::vector<std::map<String, String>> DatabaseManager::selectQuery(String query)
{
    std::vector<std::map<String, String>> result;

    if (!connect())
    {
        Serial.println("Connection failed");
        return result;
    }

    MySQL_Cursor *cur_mem = new MySQL_Cursor(conn);
    cur_mem->execute(query.c_str());

    // Fetch the columns (required before calling get_next_row())
    column_names *cols = cur_mem->get_columns();

    // Read the rows and add them to the result
    row_values *row = nullptr;
    do
    {
        row = cur_mem->get_next_row();
        if (row != nullptr)
        {
            std::map<String, String> rowMap;
            for (int i = 0; i < cols->num_fields; i++)
            {
                rowMap[cols->fields[i]->name] = row->values[i];
            }
            result.push_back(rowMap);
        }
    } while (row != nullptr);

    delete cur_mem;

    disconnect();
    return result;
}