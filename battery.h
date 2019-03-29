#pragma once
#ifndef BATTERY_H
#define BATTERY_H
#include "Object.h"
class Battery : public Object
{
private:
					int _charges;
					bool _connected;
public:
					Battery();
					Battery(const Battery& orig);
					virtual ~Battery();
					int getcharges();
					void setcharges(int charges);
					bool getConnection();
					void setConnection();
					void clearConnection();
};
#endif

