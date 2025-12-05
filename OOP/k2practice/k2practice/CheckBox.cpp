#include "CheckBox.h"

Control* CheckBox::clone() const
{
	return new CheckBox(*this);
}

CheckBox::CheckBox(int x, int y, int h, int w, const char* str, bool state) :
	TextBox(x, y, h, w, str)
{
	this->state = state;
}

bool CheckBox::getState() const
{
	return state;
}

void CheckBox::setDataDialog()
{
	state = !state;
}
