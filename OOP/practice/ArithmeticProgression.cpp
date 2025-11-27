#include "ArithmeticProgression.h"

ArithmeticProgression::ArithmeticProgression()
{
	this->firstElement = 1;
	this->difference = 1;
}

ArithmeticProgression::ArithmeticProgression(int firstElement, int differnece)
{
	this->firstElement = firstElement;
	this->difference = differnece;
}

ArithmeticProgression& ArithmeticProgression::operator+=(const ArithmeticProgression& other)
{
	this->firstElement += other.firstElement;
	this->difference += other.difference;
	return *this;
}

ArithmeticProgression& ArithmeticProgression::operator-=(const ArithmeticProgression& other)
{
	this->firstElement -= other.firstElement;
	this->difference -= other.difference;
	return *this;
}

ArithmeticProgression ArithmeticProgression::operator+(unsigned int n)
{
	return ArithmeticProgression(this->firstElement + n * this->difference, difference);
}

int ArithmeticProgression::operator[](unsigned int idx) const
{
	return this->firstElement + idx * this->difference;
}

int ArithmeticProgression::operator()(unsigned int n) const
{
	return n * (2 * this->firstElement + (n - 1) * this->difference) / 2;
}

ArithmeticProgression operator+(const ArithmeticProgression& lhs, const ArithmeticProgression& rhs)
{
	ArithmeticProgression result = lhs;
	result += rhs;
	return result;
}

ArithmeticProgression operator-(const ArithmeticProgression& lhs, const ArithmeticProgression& rhs)
{
	ArithmeticProgression result = lhs;
	result -= rhs;
	return result;
}