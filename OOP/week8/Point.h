#pragma once
class Point
{
	int x = 0;
	int y = 0;

public:
	Point(int x, int y);
	Point();
	void setX(int x);
	void setY(int y);
	int getX() const;
	int getY() const;
};

