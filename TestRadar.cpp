#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Pass Task 17 - Planetary Rover Code/battery.h"
#include "../Pass Task 17 - Planetary Rover Code/device.h"
#include "../Pass Task 17 - Planetary Rover Code/drill.h"
#include "../Pass Task 17 - Planetary Rover Code/radar.h"
#include "../Pass Task 17 - Planetary Rover Code/solar.h"
#include "../Pass Task 17 - Planetary Rover Code/rover.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTest
{
	TEST_CLASS(TestRadar)
	{
public:
		TEST_METHOD(TestConnectBattery)
		{
			Radar* radar = new Radar();
			Battery* battery = new Battery();
			battery->setcharges(5);
			radar->ConnectBattery(battery);
			Assert::AreEqual(5, radar->DeviceBattery());
			delete radar;
			delete battery;
		}
		TEST_METHOD(TestDisconnectBattery)
		{
			Radar* radar = new Radar();
			Battery* battery = new Battery();
			battery->setcharges(5);
			radar->ConnectBattery(battery);
			Assert::AreEqual(5, radar->DeviceBattery());
			radar->DisconnectBattery();
			Assert::AreEqual(-1, radar->DeviceBattery());
			delete radar;
			delete battery;
		}
		TEST_METHOD(Operate)
		{
			Radar* radar = new Radar();
			Battery* battery = new Battery();
			battery->setcharges(4);
			radar->ConnectBattery(battery);
			Assert::AreEqual(4, radar->DeviceBattery());
			string s = "";
			s = radar->Operate();
			Assert::AreEqual(0, radar->DeviceBattery());
			Assert::IsTrue(s != "");
			try
			{
				s = radar->Operate();
			}
			catch (string e)
			{
				Assert::AreEqual(string("Not enough power..."), e);
			}
			radar->DisconnectBattery();
			try
			{
				s = radar->Operate();
			}
			catch (string e)
			{
				Assert::AreEqual(string("No battery available!"), e);
			}
			delete radar;
			delete battery;
		}
		TEST_METHOD(TestCloneRadar)
		{
			Radar* radar = new Radar();
			Battery* battery = new Battery();
			battery->setcharges(20);
			radar->ConnectBattery(battery);
			Radar* cloneRadar = new Radar(*radar);
			Assert::AreEqual(radar->DeviceBattery(), cloneRadar->DeviceBattery());
			delete battery;
			delete radar;
			delete cloneRadar;
		}
	};
}

