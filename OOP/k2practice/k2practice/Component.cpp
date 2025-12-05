#include "Component.h"

void Component::free()
{
	delete[] label;
}

void Component::copyFrom(const Component& other)
{
	setLabel(other.label);
}

Component::Component()
{
	label = nullptr;
}

Component::Component(const char* label)
{
	setLabel(label);
}

Component::~Component()
{
	free();
}

Component::Component(const Component& other)
{
	copyFrom(other);
}

Component& Component::operator=(const Component& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

void Component::setLabel(const char* str)
{
	if (!str && str != label) {
		label = new char(strlen(str) + 1);
		strcpy(label, str);
	}
	else
	{
		throw std::invalid_argument("nullptr");
	}
}

std::ostream& output(std::ostream& os, const Component& c)
{
	return os << c.label;
}
