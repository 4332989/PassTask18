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
					TEST_CLASS(TestDrill)
					{
					public:
										TEST_METHOD(TestConnectBattery)
										{
															Drill* drill = new Drill();
															Battery* battery = new Battery();
															drill->ConnectBattery(battery);
															Assert::AreEqual(1, drill->DeviceBattery());
										}
										TEST_METHOD(TestDisconnectBattery)
										{
															Drill* drill = new Drill();
															Battery* battery = new Battery();
															drill->ConnectBattery(battery);
															Assert::AreEqual(1, drill->DeviceBattery());
															drill->DisconnectBattery();
															Assert::AreEqual(-1, drill->DeviceBattery());
															delete drill;
															delete battery;
										}
										TEST_METHOD(TestModifySafety)
										{
															Drill* drill = new Drill();
															drill->setSafety();
															Assert::AreEqual(true, drill->getSafety());
															drill->clearSafety();
															Assert::AreEqual(false, drill->getSafety());
															delete drill;
										}
										TEST_METHOD(TestOperate)
										{
															Drill* drill = new Drill();
															string s = "";
															drill->clearSafety();
															try
															{
																				s = drill->Operate();
															}
															catch (string e)
															{
																				Assert::AreEqual(string("No battery available!"), e);
															}
															Battery* battery = new Battery();
															drill->ConnectBattery(battery);
															try
															{
																				s = drill->Operate();
															}
															catch (string e)
															{
																				Assert::AreEqual(string("Not enough power..."), e);
															}
															battery->setcharges(10);
															s = drill->Operate();
															Assert::AreEqual(string("VRMM! VRMM!"), s);
															delete drill;
															delete battery;
										}
										TEST_METHOD(TestCloneDrill)
										{
															Drill* drill = new Drill();
															Battery* battery = new Battery();
															battery->setcharges(20);
															drill->ConnectBattery(battery);
															drill->clearSafety();
															Drill* cloneDrill = new Drill(*drill);
															Assert::AreEqual(drill->getSafety(), cloneDrill->getSafety());
															Assert::AreEqual(drill->DeviceBattery(), cloneDrill->DeviceBattery());
															delete battery;
															delete drill;
															delete cloneDrill;
										}
					};
}

