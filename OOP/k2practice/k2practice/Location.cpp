#include "Location.h"

void Location::setX(int x)
{
	this->x = x;
}

void Location::setY(int y)
{
	this->y = y;
}

int Location::getX()
{
	return x;
}

int Location::getY()
{
	return y;
}

Location::Location(int x, int y)
{
	setX(x);
	setY(y);
}
