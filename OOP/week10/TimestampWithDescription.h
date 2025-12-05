#pragma once
#include "TimeStamp.h"
class TimestampWithDescription: public TimeStamp
{
	char* descrption;
	void copyFrom();
	void free();

public:
	TimestampWithDescription();
	TimestampWithDescription(const char* description, int seconds);
	TimestampWithDescription(const TimestampWithDescription& other);
	~TimestampWithDescription();
	TimestampWithDescription& operator=(const TimestampWithDescription& other);


	void setDescription(const char* description);
	char* getDescription();

	friend std::ostream& operator<<(std::ostream& o, const TimestampWithDescription& ts);
	friend std::istream& operator>>(std::istream& o, TimestampWithDescription& ts);
};

