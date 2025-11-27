#include "SmartLight.h"

void SmartLight::turnOn() const
{
}

void SmartLight::turnOff() const
{
}

void SmartLight::printDetails() const
{
}

Device* SmartLight::clone() const
{
	return new SmartLight(*this);
}

