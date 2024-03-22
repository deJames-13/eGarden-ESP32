#ifndef DATABASE_API_H
#define DATABASE_API_H

#include <HTTPClient.h>

class DatabaseApi
{
public:
    DatabaseApi();
    // ~DatabaseApi();
    void begin(const String &serverUrl);
    void insertData(const String &data, const String &table);
    String getData(const String &data);
    void updateData(const String &data, const String &table);
    void deleteData(const String &data, const String &table);

private:
    String serverUrl;
};

#endif // DATABASE_API_H
