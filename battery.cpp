#include "Battery.h"
Battery::Battery()
{
					this->setcharges(1);
}
Battery::Battery(const Battery& orig)
{
}
Battery::~Battery()
{
}
int Battery::getcharges()
{
					return _charges;
}
void Battery::setcharges(int charges)
{
					_charges = charges;
}
bool Battery::getConnection()
{
					return _connected;
}
void Battery::setConnection()
{
					_connected = true;
}
void Battery::clearConnection()
{
					_connected = false;
}

