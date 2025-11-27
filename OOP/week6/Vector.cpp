#include "Vector.h";

void Vector::copyFrom(const Vector& other)
{
	size = other.size;
	data = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

void Vector::free()
{
	this->size = 0;
	delete[] data;
	data = nullptr;
}

Vector::Vector() {
	size = 3;
	data = new int[3];
}

Vector::Vector(int size) {
	this->size = size;
	this->data = new int[size];
}

Vector::Vector(const int* data, int size) {
	if (!data)
		return;
	this->size = size;
	this->data = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		this->data[i] = data[i];
	}

}

Vector::Vector(const Vector& other)
{
	copyFrom(other);
}

Vector& Vector::operator=(const Vector& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Vector::~Vector()
{
	free();
}

Vector& Vector::operator+=(const Vector& vector)
{
	if (this->size != vector.size) {
		return *this;
	}

	for (size_t i = 0; i < size; i++)
	{
		data[i] += vector.data[i];
	}
}

std::ostream& operator<<(std::ostream& o, const Vector& v)
{
	o << "(";
	for (size_t i = 0; i < v.size; i++)
	{
		o << v.data[i];
	}
	o << ")";
	return o;
}

std::istream& operator>>(std::istream& is, Vector& v)
{
	for (size_t i = 0; i < v.size; i++)
	{
		is >> v.data[i];
	}
	return is;
}

Vector operator+(const Vector& lhs, const Vector& rhs)
{
	Vector result = lhs;
	result += rhs;
	return result;
}

Vector& Vector::operator-=(const Vector& vector)
{
	if (this->size != vector.size) {
		return *this;
	}

	for (size_t i = 0; i < size; i++)
	{
		data[i] -= vector.data[i];
	}
}

Vector& Vector::operator*=(int num)
{
	for (size_t i = 0; i < size; i++)
	{
		data[i] *= num;
	}
}

int Vector::operator[](int idx) const
{
	return data[idx];
}

int& Vector::operator[](int idx)
{
	return data[idx];
}

bool Vector::operator!() const
{
	for (size_t i = 0; i < size; i++)
	{
		if (data[i] != 0)
			return false;
	}
	return true;
}

double Vector::operator~() const
{
	double len = 0;
	for (size_t i = 0; i < size; i++)
	{
		len += (data[i] * data[i]);
	}
	return sqrt(len);
}



Vector operator-(const Vector& lhs, const Vector& rhs)
{
	Vector result = lhs;
	result -= rhs;
	return result;
}

Vector operator*(int num, const Vector& vector)
{
	Vector result = vector;
	result *= num;
	return result;
}

Vector operator*(const Vector& vector, int num)
{
	return num * vector;
}
