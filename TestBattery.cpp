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
					TEST_CLASS(TestBattery)
					{
					public:
										TEST_METHOD(TestSetConnection)
										{
															Battery* battery = new Battery();
															battery->setConnection();
															Assert::IsTrue(battery->getConnection());
										}
										TEST_METHOD(TestClearConnection)
										{
															Battery* battery = new Battery();
															battery->clearConnection();
															Assert::IsFalse(battery->getConnection());
										}
										TEST_METHOD(TestSetCharges)
										{
															Battery* battery = new Battery();
															Assert::AreEqual(1, battery->getcharges());
															battery->setcharges(10);
															Assert::AreEqual(10, battery->getcharges());
										}
					};
}

