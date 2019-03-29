#include "drill.h"
Drill::Drill()
{
					_safetyEnabled = true;
					_battery = NULL;
}
Drill::Drill(const Drill& orig)
{
}
Drill::~Drill()
{
}
string Drill::Operate()
{
					string msg;
					if (_safetyEnabled == true)
										cout << "Safety First" << endl;
					else
					{
										if (_battery != NULL)
										{
															int battery = _battery->getcharges();
															if (battery >= 10)
															{
																				battery -= 10;
																				_battery->setcharges(battery);
																				msg = "VRMM! VRMM!";
															}
															else
																				throw exception("Not enough power...");
										}
										else
															throw exception("No battery available!");
					}
					return msg;
}
void Drill::ConnectBattery(Battery* battery)
{
					_battery = battery;
					if (battery != NULL)
										battery->setConnection();
					else
										throw exception("Battery connection failed!");
}
void Drill::DisconnectBattery()
{
					if (_battery != NULL)
										_battery->clearConnection();
					_battery = NULL;
}
int Drill::DeviceBattery()
{
					if (_battery != NULL)
										return _battery->getcharges();
					else
										return -1;
}
void Drill::setSafety()
{
					_safetyEnabled = true;
}
void Drill::clearSafety()
{
					_safetyEnabled = false;
}
bool Drill::getSafety()
{
					return _safetyEnabled;
}
Device* Drill::clone()
{
					return new Drill(*this);
}

