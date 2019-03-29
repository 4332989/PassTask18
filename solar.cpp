#include "solar.h"
solar::solar()
{
					_battery = NULL;
}
solar::solar(const solar& orig)
{
					this->_battery = orig._battery;
					this->_connection = orig._connection;
};
solar::~solar()
{
}
string solar::Operate()
{
					string msg;
					if (_battery != NULL)
					{
										_battery->setcharges(_battery->getcharges() + 1);
										msg = "Charging...";
					}
					else
										throw exception("No battery available!");
					return msg;
}
void solar::ConnectBattery(Battery* battery)
{
					_battery = battery;
					if (battery != NULL)
					{
										_battery->setConnection();
										_connection = true;
					}
					else
										throw exception("Battery connection failed!");
}
void solar::DisconnectBattery()
{
					if (_battery != NULL)
					{
										_battery->clearConnection();
										_connection = false;
					}
					_battery = NULL;
}
int solar::DeviceBattery()
{
					if (_battery != NULL)
										return _battery->getcharges();
					else
										return -1;
}
Device* solar::clone()
{
					solar* Solar = new solar(*this);
					return Solar;
}

