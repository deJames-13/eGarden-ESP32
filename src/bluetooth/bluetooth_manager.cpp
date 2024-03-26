#include "bluetooth_manager.h"

BluetoothManager::BluetoothManager(String name) : name(name){};
void BluetoothManager::begin()
{
    blues.begin(name);
    Serial.println("BluetoothManager: " + name + " is ready!");
};
String BluetoothManager::getCommand()
{
    if (blues.available())
    {
        message = String(blues.read());
        return message;
    }
    return "";
};

void BluetoothManager::sendData(String data)
{
    blues.println(data);
}