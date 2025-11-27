#pragma once
#include "StudentDB.h";
class FilteredStudentDB :public StudentDB
{
public:
	void filter(bool (*f)(const Student& s));
	void limit(unsigned n);
};

