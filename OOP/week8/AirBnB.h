#pragma once
#include "Accommodation.h"
typedef Accommodation ac;

class AirBnB
{
	ac* a;
	size_t size;
	size_t capacity;

	void resize();

public:
	void addAccomodation(const ac& ac);
	void reservePlace(int id, size_t days);

};

