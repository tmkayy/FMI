#include "Form.h"

void Form::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete data[i];
	}
	delete[] data;
	delete[] name;
}

void Form::copyFrom(const Form& other)
{
	height = other.height;
	width = other.width;
	capacity = other.capacity;
	size = other.size;
	data = new Control * [size];
	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i]->clone();
	}
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
}

void Form::resize(int newSize)
{
	Control** newData = new Control * [newSize];
	for (size_t i = 0; i < size; i++)
	{
		newData[i] = data[i];
	}
	delete[] data;
	capacity = newSize;
	data = newData;
}

void Form::moveFrom(Form&& other)
{
	data = other.data;
	name = other.name;
	size = other.size;
	capacity = other.capacity;

	other.name = nullptr;
	other.data = nullptr;
	other.size = other.capacity = 0;
}

void Form::setData(const Control** data, int size, int capacity)
{
	if (data == this->data || !data || size < 0 || capacity < 0)
		throw std::exception("man");
	delete[] this->data;
	this->data = new Control * [capacity];
	this->capacity = capacity;
	this->size = size;
	for (size_t i = 0; i < size; i++)
	{
		this->data[i] = data[i]->clone();
	}
}

Form::Form()
{
	name = nullptr;
	data = nullptr;
}

Form::~Form()
{
	free();
}

Form::Form(const Form& other)
{
	copyFrom(other);
}

Form& Form::operator=(const Form& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Form::Form(Form&& other) noexcept
{
	moveFrom(std::move(other));
}

Form& Form::operator=(Form&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

void Form::addControler(Control* c)
{
	if (!c)
		throw std::exception("bad");
	if (size == capacity) {
		resize(capacity * 2);
	}
	data[size++] = c;
}

void Form::resizeForm(int h, int w)
{
	if (h < 0 || w < 0)
		throw std::exception("bad");
	this->height = h;
	this->width = w;
}

void Form::moveControler(int idx, const Location& loc)
{
	if (loc.getX() > this->width || loc.getX() < 0)
		throw std::exception("bad");
	if (loc.getY() > this->height || loc.getY() < 0)
		throw std::exception("bad");
	data[idx]->setLoc(loc.getX(), loc.getY());
}
