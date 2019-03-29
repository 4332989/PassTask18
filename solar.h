#pragma once
#ifndef SOLAR_H
#define SOLAR_H
#include "device.h"
#include <cstdlib>
class solar : public Device
{
public:
					solar();
					solar(const solar& orig);
					virtual ~solar();
					string Operate();
					void ConnectBattery(Battery *battery);
					void DisconnectBattery();
					int DeviceBattery();
					Device* clone();
};
#endif

