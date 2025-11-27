#pragma once
#include "Control.h"
class Form
{
	int height;
	int width;
	char* name;
	Control** data;
	size_t size;
	size_t capacity;

	void free();
	void copyFrom(const Form& other);
	void resize(int newSize);
	void moveFrom(Form&& other);

	void setData(const Control** data, int size, int capacity);

public:
	Form();
	~Form();
	Form(const Form& other);
	Form& operator=(const Form& other);

	Form(Form&& other) noexcept;
	Form& operator=(Form&& other) noexcept;

	void addControler(Control* c);
	void resizeForm(int h, int w);
	void moveControler(int idx, const Location& loc);
	void change(size_t index);
};

