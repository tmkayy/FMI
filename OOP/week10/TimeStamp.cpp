#include "TimeStamp.h"

TimeStamp::TimeStamp()
{
	seconds = 0;
}

TimeStamp::TimeStamp(int seconds)
{
	setSeconds(seconds);
}

void TimeStamp::setSeconds(int seconds)
{
	if (seconds >= 0)
		this->seconds = seconds;
	else
		throw std::invalid_argument("time cant be negative");
}

int TimeStamp::getSeconds()
{
	return seconds;
}

TimeStamp& TimeStamp::operator+=(const TimeStamp& other)
{
	this->seconds += other.seconds;
	return *this;
}

std::ostream& operator<<(std::ostream& o, const TimeStamp& ts)
{
	return o << ts.seconds;
}

std::istream& operator>>(std::istream& o, TimeStamp& ts)
{
	int seconds;
	o >> seconds;
	ts.seconds = seconds;
	return o;
}
