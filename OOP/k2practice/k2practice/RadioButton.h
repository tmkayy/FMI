#pragma once
#include "Control.h"
#include "TextBox.h"
class RadioButton :Control
{
	TextBox** data;
	size_t idx;
	size_t size;

	void free();
	void copyFrom(const RadioButton& other);
	void moveFrom(RadioButton&& other);

	void setData(const TextBox** tb, int size);
public:
	RadioButton();
	RadioButton(int x, int y, int h, int w, const TextBox** tb, int size);
	~RadioButton() override;
	RadioButton(const RadioButton& other);
	RadioButton& operator=(const RadioButton& other);

	RadioButton(RadioButton&& other) noexcept;
	RadioButton& operator=(RadioButton&& other) noexcept;

	Control* clone() const override;

	void setDataDialog() override;

};

