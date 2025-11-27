#include "Memory.h"

Memory::Memory(const char* label, unsigned short capacity) : Component(label)
{
	setCapacity(capacity);
}

void Memory::setCapacity(int num)
{
	if (num >= 1 && num <= 10000)
		capacity = num;
	else
		throw std::exception("idc");
}

double Memory::price() const
{
	return 89.99 * capacity;
}

Component* Memory::clone()
{
	return new Memory(*this);
}
