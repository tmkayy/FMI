#pragma once
#include <fstream>

class Vector {
	int* data = nullptr;
	int size = 0;

	void copyFrom(const Vector& other);
	void free();

public:
	Vector();
	Vector(int size);
	Vector(const int* data, int size);
	Vector(const Vector& other);
	Vector& operator=(const Vector& other);
	~Vector();

	Vector& operator+=(const Vector& vector);
	Vector& operator-=(const Vector& vector);
	Vector& operator*=(int num);

	int operator[](int idx) const;
	int& operator[](int idx);

	bool operator!() const;

	double operator~() const;

	friend std::ostream& operator<<(std::ostream& o, const Vector& v);
	friend std::istream& operator>>(std::istream& i, Vector& v);
};

Vector operator+ (const Vector& lhs, const Vector& rhs);
Vector operator- (const Vector& lhs, const Vector& rhs);
Vector operator* (int num, const Vector& vector);
Vector operator* (const Vector& vector, int num);