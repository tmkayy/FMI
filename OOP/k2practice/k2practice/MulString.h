#pragma once
#include <iostream>

class MulString
{
	char* str;
	size_t len;
	size_t capacity;

	void free();
	void copyFrom(const MulString& other);
	void resize();
	bool contains(char c);

public:
	MulString();
	~MulString();
	MulString(const char* str, size_t len, size_t capacity);
	MulString(const MulString& other);
	MulString& operator=(const MulString& other);

	const char* getStr() const;

	MulString& operator*=(size_t k);
	friend MulString operator*(const MulString& other, size_t k);
	friend MulString operator*(size_t k, const MulString& other);

	MulString& operator%=(const MulString& other);
	friend MulString operator%(const MulString& lhs, const MulString& rhs);

	friend std::ostream& operator<<(std::ostream& o, const MulString& ms);
};

bool operator!=(const MulString& lhs, const MulString& rhs);