#pragma once
class Shape
{
protected:
	struct Point {
		int x;
		int y;

		Point(int x, int y) : x(x), y(y) {};
		Point() :x(0), y(0) {};
	};

	double getDistance(const Point& p1, const Point& p2) const;

private:
	Point* points;
	size_t pointsCount;

	void free();
	void copyFrom(const Shape& other);
	void moveFrom(Shape&& other);

public:
	Shape(size_t pointsCount);
	Shape(const Shape& other);
	Shape& operator=(const Shape& other);
	virtual ~Shape();

	Shape(Shape&& other) noexcept;
	Shape& operator= (Shape&& other) noexcept;

	void setPointAt(int pos, int x, int y);

	virtual double getPerimeter() const = 0;
	virtual double getArea() const = 0;
	virtual bool isPointIn(int x, int y) const = 0;
};

