#include "TextBox.h"

void TextBox::free()
{
	delete[] text;
}

void TextBox::copyFrom(const TextBox& other)
{
	Control::copyFrom(other);
	text = new char[strlen(other.text) + 1];
	strcpy(text, other.text);
}

void TextBox::setText(const char* str)
{
	if (!str || str == text)
		throw std::exception("bad pointer");
	delete[] text;
	text = new char[strlen(str) + 1];
	strcpy(text, str);
}

TextBox::TextBox()
{
	text = nullptr;
}

TextBox::TextBox(int x, int y, int h, int w, const char* str) :Control(x, y, h, w)
{
	setText(str);
}

TextBox::~TextBox()
{
	free();
}

TextBox::TextBox(const TextBox& other)
{
	copyFrom(other);
}

TextBox& TextBox::operator=(const TextBox& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

const char* const TextBox::getText() const
{
	return text;
}

Control* TextBox::clone() const
{
	return new TextBox(*this);
}

void TextBox::setDataDialog()
{
	char* buffer = new char[250];
	std::cin >> buffer;
	setText(buffer);

}
