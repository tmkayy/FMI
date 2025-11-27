#include "RadioButton.h"

Control* RadioButton::clone() const
{
	return new RadioButton(*this);
}

void RadioButton::setDataDialog()
{
	int idx;
	std::cin >> idx;
	if (idx >= size)
		throw std::exception("die");
	this->idx = idx;
}

void RadioButton::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete data[i];
	}
	delete[] data;
}

void RadioButton::copyFrom(const RadioButton& other)
{
	Control::copyFrom(other);
	size = other.size;
	idx = other.idx;
	data = new TextBox * [size];
	for (size_t i = 0; i < size; i++)
	{
		data[i] = new TextBox(*other.data[i]);
	}
}

void RadioButton::moveFrom(RadioButton&& other)
{
	Control::copyFrom(other);
	size = other.size;
	idx = other.idx;
	data = other.data;

	other.data = nullptr;
	idx = size = 0;
}

void RadioButton::setData(const TextBox** tb, int size)
{
	if (!tb || tb == data || size < 0)
		throw std::exception("BAD DATA");
	free();
	this->size = size;
	idx = 0;
	data = new TextBox * [size];
	for (size_t i = 0; i < size; i++)
	{
		data[i] = new TextBox(*tb[i]);
	}
}

RadioButton::RadioButton()
{
	data = nullptr;
	idx = size = 0;
}

RadioButton::RadioButton(int x, int y, int h, int w, const TextBox** tb, int size) :Control(x, y, h, w)
{
	setData(tb, size);
}

RadioButton::~RadioButton()
{
	free();
}

RadioButton::RadioButton(const RadioButton& other)
{
	copyFrom(other);
}

RadioButton& RadioButton::operator=(const RadioButton& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

RadioButton::RadioButton(RadioButton&& other) noexcept
{
	moveFrom(std::move(other));
}

RadioButton& RadioButton::operator=(RadioButton&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}
