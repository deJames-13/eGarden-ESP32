#ifndef BLUETOOTH_MANAGER_H
#define BLUETOOTH_MANAGER_H
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

class BluetoothManager
{
public:
    BluetoothManager(String name);
    void begin();
    void sendData(String data);
    String getCommand();

private:
    BluetoothSerial blues;
    String name;
    String message;
};

#endif