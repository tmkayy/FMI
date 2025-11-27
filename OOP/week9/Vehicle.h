#pragma once
#include "Registration.h"
class Vehicle
{
	Registration registration;
	char* description;

	void free();
	void copyFrom(const Vehicle& other);

public:
	Vehicle(const Registration& r, const char* description);
	~Vehicle();
	Vehicle(const Vehicle& other);

	void setDescription(const char* description);
};

