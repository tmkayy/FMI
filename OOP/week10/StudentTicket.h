#pragma once
#include "Ticket.h"
#include <iostream>
class StudentTicket :public Ticket
{
public:
	StudentTicket(const MyString& name, double price);
};

