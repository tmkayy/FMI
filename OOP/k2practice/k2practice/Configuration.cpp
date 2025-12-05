#include "Configuration.h"

void Configuration::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete data[i];
	}
	delete[] data;
}

void Configuration::copyFrom(const Configuration& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->data = new Component* [capacity];
	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i]->clone();
	}
}

void Configuration::moveFrom(Configuration&& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->data = other.data;

	other.data = nullptr;
	other.size = 0;
	other.capacity = 0;
}

void Configuration::resize(unsigned newCapacity)
{
	if (newCapacity < capacity)
		throw std::exception("die");
	Component** newData = new Component * [newCapacity];
	for (size_t i = 0; i < size; i++)
	{
		newData[i] = data[i];
	}
	delete[] data;
	capacity = newCapacity;
	data = newData;
}

Configuration::Configuration()
{
	capacity = 8;
	size = 0;
	data = new Component * [capacity];
}

Configuration::~Configuration()
{
	free();
}

Configuration::Configuration(const Configuration& other)
{
	copyFrom(other);
}

Configuration& Configuration::operator=(const Configuration& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Configuration::Configuration(Configuration&& other) noexcept
{
	moveFrom(std::move(other));
}

Configuration& Configuration::operator=(Configuration&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

void Configuration::insert(Component* component)
{
	if (!component)
		throw std::exception("man");
	if (size == capacity) {
		resize(capacity * 2);
	}
	data[size++] = component;
}

double Configuration::price() const
{
	double sum = 0;
	for (size_t i = 0; i < size; i++)
	{
		sum += data[i]->price();
	}
	return sum;
}

size_t Configuration::getSize() const
{
	return size;
}

const Component* Configuration::operator[](int num) const
{
	return data[num];
}

std::ostream& operator<<(std::ostream& os, const Configuration& c)
{
	for (size_t i = 0; i < c.size; i++)
	{
		os << c.data[i]->output(os);
	}
	return os;
}
