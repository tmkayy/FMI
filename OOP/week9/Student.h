#pragma once
#include "Person.h"
class Student : public Person
{
	char fn[11];
public:
	Student(const char* name, int age, const char* fn);
	void setFn(const char* fn);
	const char* getFn() const;
};

