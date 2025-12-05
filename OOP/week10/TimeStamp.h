#pragma once
#include "iostream"
#include <stdexcept>

class TimeStamp
{
	int seconds;

public:
	TimeStamp();
	TimeStamp(int seconds);
	void setSeconds(int seconds);
	int getSeconds();

	TimeStamp& operator+=(const TimeStamp& other);

	friend std::ostream& operator<<(std::ostream& o, const TimeStamp& ts);
	friend std::istream& operator>>(std::istream& o, TimeStamp& ts);
};

