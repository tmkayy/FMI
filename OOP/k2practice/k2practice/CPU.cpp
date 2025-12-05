#include "CPU.h"

CPU::CPU(unsigned short cores, unsigned short clockSpeed) :Component(label)
{
	setCores(cores);
	setClockSpeed(clockSpeed);
}

void CPU::setCores(int num)
{
	if (num >= 1 && num <= 8)
		cores = num;
	else
		throw std::exception("idc");
}

void CPU::setClockSpeed(int num)
{
	clockSpeed = num;
}

double CPU::price() const
{
	return cores * 29.99;
}


Component* CPU::clone()
{
	return new CPU(*this);
}

std::ostream& output(std::ostream& os, const CPU& c)
{
	return c.
}
