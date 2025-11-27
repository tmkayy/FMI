#pragma once
#include "Component.h"
class Configuration
{
	Component** data;
	size_t size;
	size_t capacity;

	void free();
	void copyFrom(const Configuration& other);
	void moveFrom(Configuration&& other);
	void resize(unsigned newCapacity);

public:
	Configuration();
	~Configuration();
	Configuration(const Configuration& other);
	Configuration& operator= (const Configuration& other);

	Configuration(Configuration&& other)noexcept;
	Configuration& operator= (Configuration&& other)noexcept;

	void insert(Component* component);
	double price() const;
	size_t getSize() const;

	const Component* operator[](int num) const;
	friend std::ostream& operator<<(std::ostream& os, const Configuration& c);
};

