#pragma once
#include "Component.h"
class Memory : public Component
{
protected:
	unsigned short capacity;

public:
	Memory() = default;
	Memory(const char* label, unsigned short capacity);

	void setCapacity(int num);

	double price() const override;

	Component* clone() override;
};

