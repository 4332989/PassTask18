#pragma once
#ifndef RADAR_H
#define RADAR_H
#include "device.h"
#include <cstdlib>
#include <ctime>
#include <random>
#include <iostream>
class Radar : public Device
{
public:
					Radar();
					Radar(const Radar& orig);
					virtual ~Radar();
					void ConnectBattery(Battery *battery);
					int DeviceBattery();
					void DisconnectBattery();
					string Operate();
					Device* clone();
};
#endif

