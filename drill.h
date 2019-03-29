#pragma once
#ifndef DRILL_H
#define	DRILL_H
#include "device.h"
class Drill : public Device
{
private:
					bool _safetyEnabled;
public:
					Drill();
					Drill(const Drill& orig);
					virtual ~Drill();
					void ConnectBattery(Battery* battery);
					void DisconnectBattery();
					int DeviceBattery();
					string Operate();
					void setSafety();
					void clearSafety();
					bool getSafety();
					Device* clone();
};
#endif

