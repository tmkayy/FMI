#include "Vehicle.h"

void Vehicle::free()
{
	delete[] description;
	description = nullptr;
}

void Vehicle::copyFrom(const Vehicle& other)
{
	this->registration = other.registration;
	strcpy(this->description, other.description);
}
