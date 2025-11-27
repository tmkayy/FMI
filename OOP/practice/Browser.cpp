#include "Browser.h"

Browser& Browser::operator+=(const Webpage& wp)
{
	if (this->count < 30) {
		this->pages[count] = wp;
		count++;
	}
	return *this;
}

Browser& Browser::operator-=(int idx)
{
	if (idx < count && idx >= 0) {
		for (size_t i = idx; i < count - 1; i++)
		{
			this->pages[i] = this->pages[i + 1];
		}
		count--;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Browser& b)
{
	for (size_t i = 0; i < b.count; i++)
	{
		os << b.pages[i];
	}
	return os;
}
