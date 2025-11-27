#include "SpecialCustomFunction.h"

void SpecialCustomFunction::free()
{
	delete[] arr;
	arr = nullptr;
	f = nullptr;
}

void SpecialCustomFunction::copyFrom(const SpecialCustomFunction& other)
{
	this->len = other.len;
	this->arr = new int[len];
	for (size_t i = 0; i < len; i++)
	{
		this->arr[i] = other.arr[i];
	}
	this->f = other.f;
}

SpecialCustomFunction::SpecialCustomFunction()
{
	this->len = 0;
	this->arr = nullptr;
	this->f = nullptr;
}

SpecialCustomFunction::~SpecialCustomFunction()
{
	free();
}

SpecialCustomFunction::SpecialCustomFunction(const int* arr, size_t len, int(*f)(int num))
{
	this->len = len;
	this->arr = new int[len];
	for (size_t i = 0; i < len; i++)
	{
		this->arr[i] = arr[i];
	}
	this->f = f;
}

SpecialCustomFunction::SpecialCustomFunction(const SpecialCustomFunction& other)
{
	copyFrom(other);
}

SpecialCustomFunction& SpecialCustomFunction::operator=(const SpecialCustomFunction& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

int SpecialCustomFunction::operator()(int num)
{
	for (size_t i = 0; i < len; i++)
	{
		if (arr[i] == num)
			return num * num;
	}
	return f(num);
}

SpecialCustomFunction& SpecialCustomFunction::operator++()
{
	for (size_t i = 0; i < len; i++)
	{
		arr[i]++;
	}
	return *this;
}

SpecialCustomFunction& SpecialCustomFunction::operator--()
{
	for (size_t i = 0; i < len; i++)
	{
		arr[i]--;
	}
	return *this;
}

SpecialCustomFunction SpecialCustomFunction::operator!()
{
	int* arr2 = new int[len];
	for (size_t i = 0; i < len; i++)
	{
		arr2[i] = arr[i] * (-1);
	}
	SpecialCustomFunction result(arr2, len, f);
	delete[] arr2;
	return result;
}
