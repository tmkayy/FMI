#pragma once
#include "Student.h"
class StudentDB
{
protected:
	Student** data;
	size_t size;
	size_t capacity;

	void free();
	void copyFrom(const StudentDB& other);
	void moveFrom(StudentDB&& other);
	void resize(size_t newCapacity);

public:
	StudentDB();
	~StudentDB();
	StudentDB(const StudentDB& other);
	StudentDB& operator=(const StudentDB& other);

	StudentDB(StudentDB&& other) noexcept;
	StudentDB& operator=(StudentDB&& other) noexcept;

	Student** getData();
	size_t getSize();
	size_t getCapacity();


	void add(Student* s);
	void remove(unsigned fn);
	Student& find(unsigned fn);
	void display();
};

