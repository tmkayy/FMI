#pragma once
#include <iostream>
class Component
{
protected:
	char* label;

	void free();
	void copyFrom(const Component& other);

public:
	Component();
	Component(const char* label);
	virtual ~Component();
	Component(const Component& other);
	Component& operator= (const Component& other);

	virtual Component* clone() = 0;

	void setLabel(const char* str);
	virtual double price() const = 0;
	virtual friend std::ostream& output(std::ostream& os, const Component& c);
};

