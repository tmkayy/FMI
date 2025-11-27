#include "Ship.h";
#include <cstring>;

void Ship::SetName(char* sn)
{
	if (!sn)
		strcpy(this->shipName, "");
	else
		strcpy(this->shipName, sn);
}

void Ship::SetYear(int year)
{
	if (year >= 0)
		this->year = year;
}

void Ship::SetClass(ShipClass sc)
{
	this->sc = sc;
}

void Ship::SetCannonCount(int cc)
{
	if (this->cannonCount >= 0)
		this->cannonCount = cc;
}

char* Ship::GetName()
{
	return this->shipName;
}

int Ship::GetYear()
{
	return this->year;
}

ShipClass Ship::GetClass()
{
	return this->sc;
}

int Ship::GetCannonCount()
{
	return this->cannonCount;
}

Ship::Ship(const char* shipName, int year, ShipClass sc, int cannonCount)
{
	if(!shipName)

}

Ship::~Ship()
{
}

Ship::Ship(const Ship& s)
{
}

Ship& Ship::operator=(const Ship& s)
{
	// TODO: insert return statement here
}

void Ship::CopyFrom(const Ship& s)
{
}

void Ship::free()
{
}
