#include "SortedStudentDB.h"

void SortedStudentDB::sortBy(bool(*f)(const Student& s1, const Student& s2))
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (f(*data[j], *data[j + 1])) {
				std::swap(data[j], data[j + 1]);
			}
		}
	}
}
