#pragma once
#include "Control.h"
class TextBox :public Control
{
protected:
	char* text;

	void free();
	void copyFrom(const TextBox& other);

	void setText(const char* str);
public:
	TextBox();
	TextBox(int x, int y, int h, int w, const char* str);
	virtual ~TextBox() override;
	TextBox(const TextBox& other);
	TextBox& operator=(const TextBox& other);

	const char* const getText() const;

	Control* clone() const override;
	void setDataDialog() override;
};

