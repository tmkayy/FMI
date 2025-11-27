#include "ComputerStore.h"
#include <string>
#pragma warning (disable:4996)

void ComputerStore::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete computers[i];
	}
	delete[] computers;
	delete[] name;
}

void ComputerStore::copyFrom(const ComputerStore& other)
{
	size = other.size;
	capacity = other.capacity;

	computers = new Computer * [capacity];
	for (size_t i = 0; i < capacity; i++)
	{
		computers[i] = new Computer(*other.computers[i]);
	}
	name = new char[strlen(other.name)];
	strcpy(name, other.name);
}

void ComputerStore::moveFrom(ComputerStore&& other)
{
	computers = other.computers;
	size = other.size;
	capacity = other.capacity;

	other.size = 0;
	other.capacity = 0;
	other.computers = nullptr;
}

void ComputerStore::resize(size_t newCapacity)
{
	Computer** newPtr = new Computer * [newCapacity] {nullptr };
	for (size_t i = 0; i < capacity; i++)
	{
		newPtr[i] = computers[i];
	}
	delete[] computers;
	computers = newPtr;
	capacity = newCapacity;
}

ComputerStore::ComputerStore()
{
	capacity = 0;
	computers = nullptr;
	size = 0;
	name = nullptr;
}

ComputerStore::~ComputerStore()
{
	free();
}

ComputerStore::ComputerStore(const ComputerStore& other)
{
	copyFrom(other);
}

ComputerStore& ComputerStore::operator=(const ComputerStore& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

ComputerStore::ComputerStore(ComputerStore&& other) noexcept
{
	moveFrom(std::move(other));
}

ComputerStore& ComputerStore::operator=(ComputerStore&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}
