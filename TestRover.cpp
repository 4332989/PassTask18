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
					TEST_CLASS(TestRover)
					{
					public:
										TEST_METHOD(Attach)
										{
															Rover* rover = new Rover();
															Battery* battery = new Battery();
															rover->InsertBattery(battery);
															rover->AttachDevice(new Radar());
															Assert::AreEqual(1, rover->deviceCount());
															delete battery;
															delete rover;
										}
										TEST_METHOD(Detach)
										{
															Rover* rover = new Rover();
															Battery* battery = new Battery();
															battery->setcharges(10);
															rover->InsertBattery(battery);
															Radar* radar1 = new Radar();
															Radar* radar2 = new Radar();
															rover->AttachDevice(radar1);
															rover->AttachDevice(radar2);
															Assert::AreEqual(2, rover->deviceCount());
															rover->DetachDevice(radar1);
															Assert::AreEqual(1, rover->deviceCount());
															delete radar1;
															rover->DetachDevice(radar2);
															Assert::AreEqual(0, rover->deviceCount());
															delete radar2;
															delete battery;
															delete rover;
										}
										TEST_METHOD(Operate)
										{
															Rover* rover = new Rover();
															Radar* radar = new Radar();

															try
															{
																				rover->AttachDevice(radar);
															}
															catch (string error) {

																				Assert::AreEqual(string("No battery available!"), error);
																				rover->DetachDevice(radar);
															}

															Battery* battery = new Battery();
															rover->InsertBattery(battery);
															battery->setcharges(20);

															rover->AttachDevice(radar);
															rover->OperateDevice();

															Assert::AreEqual(16, battery->getcharges());
															rover->DetachDevice(radar);
															delete radar;

															Drill* drill = new Drill();
															rover->AttachDevice(drill);
															drill->clearSafety();
															rover->OperateDevice();

															Assert::AreEqual(6, battery->getcharges());
															rover->DetachDevice(drill);
															delete drill;

															solar* solarpanel = new solar();
															rover->AttachDevice(solarpanel);
															rover->OperateDevice();

															Assert::AreEqual(7, battery->getcharges());
															rover->DetachDevice(solarpanel);
															delete solarpanel;

															delete battery;
															delete rover;
										}
										
										TEST_METHOD(ObjectAlliasing)
										{
															try {
																				Battery* battery = new Battery();
																				battery->setcharges(100);
																				Rover* rover = new Rover();
																				rover->InsertBattery(battery);
																				rover->AttachDevice(new Radar());//connect to battery with 100 power unit
																				rover->AttachDevice(new solar());//same as previous
																				rover->AttachDevice(new Drill());//same as previous

																				Assert::AreEqual(5, Object::getCount());
																				Rover* newRover = new Rover(*rover);

																				Assert::AreEqual(9, Object::getCount());
																				delete rover;
																				delete newRover;
																				delete battery;
																				
															}
															catch (string s) {
																				cerr << s << endl;
															}
										}
					};

}