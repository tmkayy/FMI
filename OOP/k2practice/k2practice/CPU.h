#pragma once
#include "Component.h"
class CPU : public Component
{
protected:
	unsigned short cores;
	unsigned short clockSpeed;
public:
	CPU() = default;
	CPU(unsigned short cores, unsigned short clockSpeed);

	void setCores(int num);
	void setClockSpeed(int num);

	friend std::ostream& output(std::ostream& os, const CPU& c);

	double price() const override;

	Component* clone() override;
};

