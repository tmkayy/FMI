#pragma once
#include "Point.h";
static size_t counter = 0;

enum class Type {
	Apartment, Hotel, Villa
};

class Accommodation
{
	size_t id;
	char* name;
	size_t nameLen;
	size_t nameCapacity;
	Type type;
	Point location;
	double price;
	bool isBooked;
	size_t daysToStay;

	void free();
	void copyFrom(const Accommodation& other);

public:
	Accommodation();
	Accommodation(const char* name, const Type& type, const Point& location,
		double price, bool isBooked, size_t daysToStay);
	Accommodation(const Accommodation& other);
	~Accommodation();
	Accommodation& operator= (const Accommodation& other);

	void setName(const char* name);
	void setType(const Type& type);
	void setLocation(const Point& location);
	void setPrice(double price);
	void setDaysToStay(size_t n);

	char* getName() const;
	Type getType()const;
	const Point& getLocation()const;
	double getPrice()const;
	size_t getDaysToStay()const;

	void book(size_t daysToStay);
	void unbook();
	double getEarnings();
};

