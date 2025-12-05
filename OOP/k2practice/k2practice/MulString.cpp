#include "MulString.h"
#pragma warning (disable:4996)

void MulString::free()
{
	delete[] str;
	len = 0;
	capacity = 0;
	str = nullptr;
}

void MulString::copyFrom(const MulString& other)
{
	this->capacity = other.capacity;
	this->len = other.len;
	this->str = new char[capacity];
	strcpy(this->str, other.str);
}

void MulString::resize()
{
	char* newStr = new char[capacity * 2 + 1];
	strcpy(newStr, str);
	free();
	str = newStr;
	capacity *= 2;
}

bool MulString::contains(char c)
{
	for (size_t i = 0; i < len; i++)
	{
		if (str[i] == c)
			return true;
	}
	return false;
}

MulString::MulString()
{
	str = nullptr;
	len = 0;
	capacity = 0;
}

MulString::~MulString()
{
	free();
}

MulString::MulString(const char* str, size_t len, size_t capacity)
{
	this->capacity = capacity;
	this->len = len;
	this->str = new char[capacity];
	strcpy(this->str, str);
}

MulString::MulString(const MulString& other)
{
	copyFrom(other);
}

MulString& MulString::operator=(const MulString& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

const char* MulString::getStr() const
{
	return str;
}

MulString& MulString::operator*=(size_t k)
{
	size_t newLen = len * k;
	size_t newCapacity = capacity;
	if (capacity < newLen) {
		newCapacity = newLen * 2 + 1;
	}
	char* newStr = new char[newCapacity];
	for (size_t i = 0; i < newLen; i++)
	{
		for (size_t j = 0; j < len; j++)
		{
			newStr[i++] = str[j];
		}
	}
	newStr[newLen] = '/0';
	free();
	this->len = newLen;
	this->capacity = newCapacity;
	strcpy(str, newStr);
	delete[] newStr;
	return *this;
}

MulString& MulString::operator%=(const MulString& other)
{
	while (this->len + other.len > capacity)
	{
		this->resize();
	}
	for (size_t i = 0; i < other.len; i++)
	{
		if (!this->contains(other.str[i])) {
			this->str[len] = other.str[i];
			len++;
		}
	}
	this->str[len] = '\0';
	return *this;
}

MulString operator*(const MulString& other, size_t k)
{
	MulString res = other;
	res *= k;
	return res;
}

MulString operator*(size_t k, const MulString& other)
{
	MulString res = other;
	res *= k;
	return res;
}

MulString operator%(const MulString& lhs, const MulString& rhs)
{
	MulString res = lhs;
	res %= rhs;
	return res;
}

std::ostream& operator<<(std::ostream& o, const MulString& ms)
{
	return o << ms.str;
}

bool operator!=(const MulString& lhs, const MulString& rhs)
{
	return strcmp(lhs.getStr(), rhs.getStr());
}
