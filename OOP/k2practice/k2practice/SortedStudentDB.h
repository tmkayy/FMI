#pragma once
#include "StudentDB.h"
class SortedStudentDB :public StudentDB
{
public:
	void sortBy(bool (*f)(const Student& s1, const Student& s2));
};

