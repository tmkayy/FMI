#pragma once
class SpecialCustomFunction
{
	int* arr;
	size_t len;
	int (*f) (int num);

	void free();
	void copyFrom(const SpecialCustomFunction& other);

public:
	SpecialCustomFunction();
	~SpecialCustomFunction();
	SpecialCustomFunction(const int* arr, size_t len, int (*f) (int num));
	SpecialCustomFunction(const SpecialCustomFunction& other);
	SpecialCustomFunction& operator=(const SpecialCustomFunction& other);

	int operator() (int num);
	SpecialCustomFunction& operator++();
	SpecialCustomFunction& operator--();
	SpecialCustomFunction operator!();
};

