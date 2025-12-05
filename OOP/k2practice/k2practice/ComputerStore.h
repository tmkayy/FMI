#pragma once
#include "Computer.h"
class ComputerStore
{
	char* name;
	Computer** computers;
	size_t size;
	size_t capacity;

	void free();
	void copyFrom(const ComputerStore& other);
	void moveFrom(ComputerStore&& other);
	void resize(size_t newCapacity);

public:
	ComputerStore();
	~ComputerStore();
	ComputerStore(const ComputerStore& other);
	ComputerStore& operator= (const ComputerStore& other);

	ComputerStore(ComputerStore&& other) noexcept;
	ComputerStore& operator= (ComputerStore&& other) noexcept;


};

