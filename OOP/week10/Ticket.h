#pragma once
#include "MyString.h"
class Ticket
{
	MyString name;
	double price;

public:
	Ticket();
	Ticket(const Ticket& other);
	Ticket(const MyString& name, double price);

	friend std::ostream& operator<<(std::ostream& o, const Ticket& s);
};

