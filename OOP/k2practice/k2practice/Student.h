#pragma once
#include <string>
class Student
{
	std::string name;
	unsigned fn;
	unsigned course;

public:
	Student* clone();
	std::string getName();
	unsigned getFn();
	unsigned getCourse();
	void print();
};

