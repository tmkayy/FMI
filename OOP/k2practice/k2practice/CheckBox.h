#pragma once
#include "TextBox.h"
class CheckBox:TextBox
{
	bool state = 0;

public:
	Control* clone() const override;
	CheckBox() = default;
	CheckBox(int x, int y, int h, int w, const char* str, bool state);
	bool getState() const;
	void setDataDialog() override;
};

