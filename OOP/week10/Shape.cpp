#include "Shape.h"
#include <iostream>

double Shape::getDistance(const Point& p1, const Point& p2) const
{
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void Shape::free()
{
	delete[] points;
	points = nullptr;
	pointsCount = 0;
}

void Shape::copyFrom(const Shape& other)
{
	points = new Point[other.pointsCount];
	pointsCount = other.pointsCount;
	for (size_t i = 0; i < pointsCount; i++)
	{
		points[i] = other.points[i];
	}
}

void Shape::moveFrom(Shape&& other)
{
	points = other.points;
	pointsCount = other.pointsCount;
	other.points = nullptr;
}

Shape::Shape(size_t pointsCount)
{
	this->pointsCount = pointsCount;
	points = new Point[pointsCount];
}

Shape::Shape(const Shape& other)
{
	copyFrom(other);
}

Shape& Shape::operator=(const Shape& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Shape::~Shape()
{
	free();
}

Shape::Shape(Shape&& other) noexcept
{
	moveFrom(std::move(other));
}

Shape& Shape::operator=(Shape&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

void Shape::setPointAt(int pos, int x, int y)
{
	pos--;
	if (pos < 0 || pos >= pointsCount)
		throw std::invalid_argument("invalid position given");

	points[pos] = { x,y };
}

