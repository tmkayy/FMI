#pragma once
class Location
{
	int x = 0;
	int y = 0;

public:
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();

	Location(int x, int y);
	Location() = default;
};

