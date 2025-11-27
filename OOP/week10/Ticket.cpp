#include "Ticket.h"
#include <iostream>

Ticket::Ticket()
{
	this->name = MyString();
	this->price = 0;
}

Ticket::Ticket(const Ticket& other)
{
	this->name = other.name;
	this->price = other.price;
}

Ticket::Ticket(const MyString& name, double price)
{
	this->name = name;
	this->price = price;
}

std::ostream& operator<<(std::ostream& o, const Ticket& s)
{
	return o << s.name << s.price;
}
