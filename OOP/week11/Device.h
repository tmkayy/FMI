#pragma once
#include "MyString.h"
class Device
{
protected:
	MyString name;
	MyString manufacturer;
	double price = 0;
public:
	virtual void turnOn() const = 0;
	virtual void turnOff() const = 0;
	virtual void printDetails() const = 0;
	virtual ~Device() = default;
	virtual Device* clone() const = 0;
	Device(const MyString& name, const MyString& manufacturer, double price);
};