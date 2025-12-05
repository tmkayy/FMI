#include "StudentDB.h"
#include <iostream>
#include <stdexcept>

void StudentDB::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete data[i];
	}
	delete[] data;
}

void StudentDB::copyFrom(const StudentDB& other)
{
	size = other.size;
	capacity = other.capacity;
	data = new Student * [capacity];
	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i]->clone();
	}
}

void StudentDB::moveFrom(StudentDB&& other)
{
	size = other.size;
	capacity = other.capacity;
	data = other.data;

	other.size = 0;
	other.capacity = 0;
	other.data = nullptr;
}

void StudentDB::resize(size_t newCapacity)
{
	Student** newData = new Student * [newCapacity];
	for (size_t i = 0; i < size; i++)
	{
		newData[i] = data[i];
	}
	delete[] data;
	capacity = newCapacity;
	data = newData;
}

StudentDB::StudentDB()
{
	size = 0;
	capacity = 8;
	data = new Student * [capacity];
}

StudentDB::~StudentDB()
{
	free();
}

StudentDB::StudentDB(const StudentDB& other)
{
	copyFrom(other);
}

StudentDB& StudentDB::operator=(const StudentDB& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

StudentDB::StudentDB(StudentDB&& other) noexcept
{
	moveFrom(std::move(other));
}

StudentDB& StudentDB::operator=(StudentDB&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Student** StudentDB::getData()
{
	return data;
}

size_t StudentDB::getSize()
{
	return size;
}

size_t StudentDB::getCapacity()
{
	return capacity;
}

void StudentDB::add(Student* s)
{
	if (s == nullptr) {
		return;
	}
	if (size == capacity) {
		resize(capacity * 2);
	}
	data[size] = s;
	size++;
}

void StudentDB::remove(unsigned fn)
{
	for (size_t i = 0; i < size; i++)
	{
		if (data[i]->getFn() == fn) {
			delete data[i];
			for (size_t j = 0; j < size - 1; j++)
			{
				data[j] = data[j + 1];
			}
			size--;
			data[size] = nullptr;
			return;
		}
	}
}

Student& StudentDB::find(unsigned fn)
{
	for (size_t i = 0; i < size; i++)
	{
		if (data[i]->getFn() == fn) {
			return *data[i];
		}
	}
	throw::std::exception("not found");
}

void StudentDB::display()
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << i << '.' << std::endl;
		data[i]->print();
	}
}
