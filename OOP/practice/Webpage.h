#pragma once
#include <iostream>
class Webpage
{
	char* adress;
	size_t adressLen;
	char* ip;
	size_t ipLen;

	void free();
	void copyFrom(const Webpage& other);

public:
	Webpage();
	Webpage(const char* adress, const char* ip);
	Webpage(const Webpage& other);
	~Webpage();
	Webpage& operator=(const Webpage& other);

	char* getAdress() const;
	size_t getAdressLen() const;
	char* getIp() const;
	size_t getIpLen() const;

	friend std::ostream& operator<<(std::ostream& os, const Webpage& wp);
	friend std::istream& operator>>(std::istream& is, Webpage& wp);
};

