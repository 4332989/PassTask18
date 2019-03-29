#include "radar.h"
Radar::Radar()
{
					_battery = NULL;
}
Radar::Radar(const Radar& orig)
{
}
Radar::~Radar()
{
}
string Radar::Operate()
{
					string msg;
					if (_battery != NULL)
					{
										if (_battery->getcharges() >= 4)
										{
															srand(time(NULL));
															_battery->setcharges(_battery->getcharges() - 4);
															for (int i = 0; i < 4; i++)
															{
																				if (rand() % 2)
																									msg += "PING\n";
																				else
																									msg += "PONG\n";
															}
										}
										else
															throw exception("Not enough power...");
					}
					else
										throw exception("No battery available!");
					return msg;
}
void Radar::ConnectBattery(Battery* battery)
{
					_battery = battery;
					if (_battery != NULL)
										_battery->setConnection();
					else
										throw exception("Battery connection failed!");
}
void Radar::DisconnectBattery()
{
					if (_battery != NULL)
										_battery->clearConnection();
					_battery = NULL;
}
int Radar::DeviceBattery()
{
					if (_battery != NULL)
										return _battery->getcharges();
					else
										return -1;
}
Device* Radar::clone()
{
					Radar* radar = new Radar(*this);
					return radar;
}

