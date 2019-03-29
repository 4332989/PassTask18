#include "Rover.h"
Rover::Rover()
{
}
Rover::Rover(const Rover& orig)
{
					_batteries = orig._batteries;
					_devices.clear();
					for (int i = 0; i < orig._devices.size(); i++)
					{
										this->_devices.push_back(orig._devices.at(i)->clone());
					}
}
Rover::~Rover()
{
					for (int i = 0; i < _devices.size(); i++)
					{
										if (_devices.at(i) != NULL)
															delete _devices.at(i);
					}
}
void Rover::AttachDevice(Device* device)
{
					_devices.push_back(device);
					int nMaxBattery = 0;
					if (_batteries.size() == 0)
										throw exception("No battery available!");
					for (int i = 0; i < _batteries.size(); i++)
					{
										if (_batteries.at(i)->getcharges() > nMaxBattery)
										{
															nMaxBattery = _batteries.at(i)->getcharges();
															device->ConnectBattery(_batteries.at(i));
										}
					}
}
void Rover::DetachDevice(Device* device)
{
					for (int i = 0; i < _devices.size(); i++)
					{
										if (_devices.at(i) == device)
										{
															_devices.at(i)->DisconnectBattery();
															_devices.erase(_devices.begin() + i);
															break;
										}
					}
}
void Rover::InsertBattery(Battery* battery)
{
					_batteries.push_back(battery);
}
void Rover::OperateDevice()
{
					for (int i = 0; i < _devices.size(); i++)
					{
										try
										{
															_devices.at(i)->Operate();
										}
										catch (string e)
										{
															if (e == ("No battery available!"))
															{
																				this->AttachDevice(_devices.at(i));
																				_devices.at(i)->Operate();
															}
															else
																				throw "Unknown Error Occur While Operating Device";
										}
					}
}
int Rover::deviceCount()const
{
					return _devices.size();
}

