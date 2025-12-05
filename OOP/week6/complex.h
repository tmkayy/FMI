#pragma once
#include <fstream>

class ComplexNumber {
	double real;
	double im;

public:
	ComplexNumber();
	ComplexNumber(double real, double im);

	double getReal() const;
	double getIm() const;

	void setReal(double real);
	void setIm(double im);

	ComplexNumber& operator+=(const ComplexNumber& other);
	ComplexNumber& operator-=(const ComplexNumber& other);
	ComplexNumber& operator*=(const ComplexNumber& other);
	ComplexNumber& operator/=(const ComplexNumber& other);

	friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& c);
	friend std::istream& operator>>(std::istream& os, const ComplexNumber& c);
};

bool operator==(const ComplexNumber& lhs, const ComplexNumber& rhs);
bool operator!=(const ComplexNumber& lhs, const ComplexNumber& rhs);