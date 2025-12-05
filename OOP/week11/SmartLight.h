#pragma once
#include "Device.h"
class SmartLight : public Device
{
	int brightnessLevel = 0;
public:
	void turnOn() const override;
	void turnOff() const override;
	void printDetails() const override;
	Device* clone() const override;
	SmartLight(const MyString& name, const MyString& manufacturer, double price, int brightnessLevel)
		:Device(name, manufacturer, price){ }
};

