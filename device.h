#ifndef DEVICE_H
#define DEVICE_H
#include <string>
#include <iostream>
#include "Battery.h"
#include "Object.h"
using namespace std;
class Device : public Object
{
protected:
					Battery* _battery;
					bool _connection;
public:
					virtual string Operate() = 0;
					virtual void ConnectBattery(Battery *battery) = 0;
					virtual void DisconnectBattery() = 0;
					virtual Device* clone() = 0;
};
#endif

