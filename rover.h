#pragma once
#ifndef ROVER_H
#define	ROVER_H
#include "Radar.h"
#include "Device.h"
#include <iostream>
#include <cstdlib>
#include <vector>
class Rover : public Object
{
private:
					vector <Battery*> _batteries;
					vector <Device*> _devices;
public:
					Rover();
					Rover(const Rover& orig);
					virtual ~Rover();
					void AttachDevice(Device* device);
					void DetachDevice(Device* device);
					void InsertBattery(Battery* battery);
					void OperateDevice();
					int deviceCount() const;
};
#endif	/* ROVER_H */

