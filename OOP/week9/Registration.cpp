#include "Registration.h"

bool Registration::isLetter(char c)
{
	return c >= 'A' && c <= 'Z';
}

bool Registration::isNumber(char c)
{
	return c >= '0' && c <= '9';
}

bool Registration::validateSize(const char* registration)
{
	if (!registration)
		return false;

	this->len = strlen(registration);
	if (len != MAX_REGISTRATION_LEN1 || len != MAX_REGISTRATION_LEN2);
	return false;

	smaller = (this->len == MAX_REGISTRATION_LEN2);
	return true;
}

bool Registration::validatePlace(const char* registration)
{
	if (!smaller) {
		for (size_t i = 0; i < MAX_SYMBOLS; i++)
		{
			if (!isLetter(registration[i]))
				return false;
		}
	}
	else
	{
		if (!isLetter(registration[0]))
			return false;
	}

	return true;
}

bool Registration::validateSymbols(const char* registration)
{
	if (!smaller) {
		for (size_t i = 0; i < MAX_SYMBOLS; i++)
		{
			if (!isLetter(registration[START_OF_SYMBOLS + i]))
				return false;
		}
	}
	else
	{
		for (size_t i = 0; i < MAX_SYMBOLS; i++)
		{
			if (!isLetter(registration[START_OF_SYMBOLS + i - 1]))
				return false;
		}
	}

	return true;
}

bool Registration::validateNumbers(const char* registration)
{
	if (!smaller) {
		for (size_t i = 0; i < MAX_SYMBOLS; i++)
		{
			if (!isNumber(registration[START_OF_NUMS + i]))
				return false;
		}
	}
	else
	{
		for (size_t i = 0; i < MAX_SYMBOLS; i++)
		{
			if (!isNumber(registration[START_OF_NUMS + i - 1]))
				return false;
		}
	}

	return true;
}

void Registration::setPlace(const char* registration)
{
	if (!validatePlace(registration))
		throw std::invalid_argument("invalid place");

	if (smaller) {
		place[0] = registration[0];
	}
	else {
		place[0] = registration[0];
		place[1] = registration[1];
	}
}

void Registration::setSymbols(const char* registration)
{
	if (!validateSymbols(registration))
		throw std::invalid_argument("invalid place");

	if (smaller) {
		place[0] = registration[START_OF_SYMBOLS - 1];
		place[1] = registration[START_OF_SYMBOLS];
	}
	else {
		place[0] = registration[START_OF_SYMBOLS];
		place[1] = registration[START_OF_SYMBOLS + 1];
	}
}

void Registration::setNumber(const char* registration)
{
	if (!validateNumbers(registration))
		throw std::invalid_argument("invalid place");

	if (smaller) {
		int num = 0;
		for (size_t i = 0; i < MAX_SYMBOLS; i++)
		{
			if (!isNumber(registration[START_OF_NUMS + i - 1])) {
				num *= 10;
				num += (registration[START_OF_NUMS + i - 1] - '0');
			}
		}
	}
	else {
		int num = 0;
		for (size_t i = 0; i < MAX_SYMBOLS; i++)
		{
			if (!isNumber(registration[START_OF_NUMS + i])) {
				num *= 10;
				num += (registration[START_OF_NUMS + i] - '0');
			}
		}
	}
}

Registration::Registration(const char* registration)
{
	validateSize(registration);
	setPlace(registration);
	setNumber(registration);
	setSymbols(registration);
}

bool operator==(const Registration& lhs, const Registration& rhs)
{
	if (lhs.number != rhs.number)
		return false;
	for (size_t i = 0; i < MAX_NUMBERS; i++)
	{
		if (lhs.symbols[i] != rhs.symbols[i])
			return false;
	}
	if (lhs.smaller != rhs.smaller)
		return false;
	if (lhs.smaller && rhs.smaller) {
		if (lhs.place[0] != rhs.place[0])
			return false;
	}
	else
	{
			if (lhs.place[0] != rhs.place[0])
				return false;
			if (lhs.place[1] != rhs.place[1])
				return false;
	}
	return true;
}
