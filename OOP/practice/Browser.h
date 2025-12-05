#pragma once
#include "Webpage.h"

class Browser
{
	Webpage pages[30];
	size_t count;

public:
	Browser& operator+=(const Webpage& wp);
	Browser& operator-=(int idx);
	friend std::ostream& operator<<(std::ostream& os, const Browser& b);
};

