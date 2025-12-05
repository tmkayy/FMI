#include "FilteredStudentDB.h"

void FilteredStudentDB::filter(bool(*f)(const Student& s))
{
	Student** newData = new Student * [capacity];
	int newSize = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (f(*data[i])) {
			newData[newSize++] = data[i];
		}
		else {
			delete data[i];
		}
	}
	delete[] data;
	size = newSize;
	data = newData;
}

void FilteredStudentDB::limit(unsigned n)
{
	if (n > size)
		throw std::exception("kys");
	for (size_t i = n; i < size; i++)
	{
		delete data[i];
	}
	size = n;
}
