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
					TEST_CLASS(TestSolar)
					{
					public:
										TEST_METHOD(TestConnectBattery)
										{
															solar* solarpanel = new solar();
															Battery* battery = new Battery();
															solarpanel->ConnectBattery(battery);
																				Assert::AreEqual(1, solarpanel->DeviceBattery());
										}
										TEST_METHOD(TestDisconnectBattery)
										{
															solar* solarpanel = new solar();
															Battery* battery = new Battery();
															solarpanel->ConnectBattery(battery);
															Assert::AreEqual(1, solarpanel->DeviceBattery());
															solarpanel->DisconnectBattery();
															Assert::AreEqual(-1, solarpanel->DeviceBattery());
															delete solarpanel;
																				delete battery;
										}
										TEST_METHOD(TestOperate)
										{
															solar* solarpanel = new solar();
															string s = "";
															try
															{
																				s = solarpanel->Operate();
															}
															catch (string e)
															{ 
																				Assert::AreEqual(string("No battery available!"), e);
																				Battery * battery = new Battery();
																				Assert::AreEqual(1, battery->getcharges());
																				solarpanel->ConnectBattery(battery);
																				s = solarpanel->Operate();
																				Assert::AreEqual(string("Charging..."), s);
																									Assert::AreEqual(2, solarpanel->DeviceBattery());
										}}
										TEST_METHOD(TestCloneSolarPanel)
										{
															solar* solarpanel = new solar();
															Battery* battery = new Battery();
															battery->setcharges(20);
															solarpanel->ConnectBattery(battery);
															solar* cloneSolarpanel = new solar(*solarpanel);
															Assert::AreEqual(solarpanel->DeviceBattery(), cloneSolarpanel->DeviceBattery());
															delete battery;
															delete solarpanel;
																				delete cloneSolarpanel;
										}
					};
}

