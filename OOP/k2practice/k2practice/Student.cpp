#include "Student.h"
#include <iostream>;

Student* Student::clone()
{
	return new Student(*this);
}

std::string Student::getName()
{
	return name;
}

unsigned Student::getFn()
{
	return fn;
}

unsigned Student::getCourse()
{
	return course;
}

void Student::print()
{
	std::cout << name << ' ' << fn << ' ' << course << std::endl;
}
