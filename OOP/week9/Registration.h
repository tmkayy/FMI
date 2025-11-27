#pragma once
#include "Constants.h"
#include "stdexcept";

class Registration
{
	char place[MAX_SYMBOLS];
	int number;
	char symbols[MAX_SYMBOLS];
	size_t len;
	bool smaller;

	bool isLetter(char c);
	bool isNumber(char c);

	bool validateSize(const char* registration);
	bool validatePlace(const char* registration);
	bool validateSymbols(const char* registration);
	bool validateNumbers(const char* registration);

public:
	void setPlace(const char* registration);
	void setSymbols(const char* registration);
	void setNumber(const char* registration);

	Registration(const char* registration);

	friend bool operator==(const Registration& lhs, const Registration& rhs);
};
