#include "Accommodation.h"
#include <cstring>
#include <stdexcept>

void Accommodation::free()
{
	delete[] name;
	name = nullptr;
	nameLen = 0;
	nameCapacity = 0;
}

void Accommodation::copyFrom(const Accommodation& other)
{
	id = counter;
	counter++;
	setName(other.name);
	setType(other.type);
	setLocation(other.location);
	setPrice(other.price);
	this->isBooked = other.isBooked;
	setDaysToStay(other.daysToStay);
}

Accommodation::Accommodation()
{
	id = counter;
	counter++;
	name = nullptr;
	nameLen = 0;
	nameCapacity = 0;
	type = (Type)0;
	location = Point();
	price = 0;
	isBooked = 0;
	daysToStay = 0;
}

Accommodation::Accommodation(const char* name, const Type& type, const Point& location, double price, bool isBooked, size_t daysToStay)
{
	id = counter;
	counter++;
	setName(name);
	setType(type);
	setLocation(location);
	setPrice(price);
	this->isBooked = isBooked;
	setDaysToStay(daysToStay);
}

Accommodation::Accommodation(const Accommodation& other)
{
	copyFrom(other);
}

Accommodation::~Accommodation()
{
	free();
}

Accommodation& Accommodation::operator=(const Accommodation& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

void Accommodation::setName(const char* name)
{
	if (!name && this->name != name) {
		delete[] this->name;
		this->nameLen = strlen(name);
		this->nameCapacity = nameLen;
		name = new char[nameLen];
		strcpy(this->name, name);
	}
	else
		throw std::exception("invalid string adress");
}

void Accommodation::setType(const Type& type)
{
	this->type = type;
}

void Accommodation::setLocation(const Point& location)
{
	this->location = Point(location.getX(), location.getY());
}

void Accommodation::setPrice(double price)
{
	if (price >= 0) {
		this->price = price;
	}
	else {
		throw std::exception("invalid price");
	}
}

void Accommodation::setDaysToStay(size_t n)
{
	this->daysToStay = n;
}

char* Accommodation::getName() const
{
	return this->name;
}

Type Accommodation::getType() const
{
	return this->type;
}

const Point& Accommodation::getLocation() const
{
	return this->location;
}

double Accommodation::getPrice() const
{
	return this->price;
}

size_t Accommodation::getDaysToStay() const
{
	return this->daysToStay;
}

void Accommodation::book(size_t daysToStay)
{
	this->isBooked = true;
	this->daysToStay += daysToStay;
}

void Accommodation::unbook()
{
	this->isBooked = false;
}

double Accommodation::getEarnings()
{
	if (!isBooked)
		return 0;
	return daysToStay * price;
}
