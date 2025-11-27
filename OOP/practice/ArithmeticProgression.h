#pragma once

class ArithmeticProgression
{
	int firstElement = 1;
	int difference = 1;

public:
	ArithmeticProgression();
	ArithmeticProgression(int firstElement, int differnece);

	ArithmeticProgression& operator+=(const ArithmeticProgression& other);
	ArithmeticProgression& operator-=(const ArithmeticProgression& other);
	ArithmeticProgression operator+(unsigned int n);
	int operator[](unsigned int idx) const;
	int operator()(unsigned int n) const;

};

ArithmeticProgression operator+ (const ArithmeticProgression& lhs, const ArithmeticProgression& rhs);
ArithmeticProgression operator- (const ArithmeticProgression& lhs, const ArithmeticProgression& rhs);