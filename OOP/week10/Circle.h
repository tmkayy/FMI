#pragma once
#include "Shape.h"
class Circle :public Shape
{
public:
	Circle() : Shape(2) {};

	double getPerimeter() const override;
	double getArea() const = 0;
	bool isPointIn(int x, int y) const = 0;
};