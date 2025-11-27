#include "Webpage.h"
#include <iostream>

void Webpage::free()
{
	delete[] adress;
	delete[] ip;
	adress = nullptr;
	ip = nullptr;
	adressLen = 0;
	ipLen = 0;
}

void Webpage::copyFrom(const Webpage& other)
{
	this->adressLen = other.adressLen;
	this->ipLen = other.ipLen;
	this->adress = new char[adressLen];
	this->ip = new char[ipLen];
	strcpy(this->adress, other.adress);
	strcpy(this->ip, other.ip);
}

Webpage::Webpage() : Webpage("none", "none")
{
}

Webpage::Webpage(const char* adress, const char* ip)
{
	this->adressLen = strlen(adress);
	this->ipLen = strlen(ip);
	this->adress = new char[adressLen];
	this->ip = new char[ipLen];
	strcpy(this->adress, adress);
	strcpy(this->ip, ip);
}

Webpage::Webpage(const Webpage& other)
{
	copyFrom(other);
}

Webpage::~Webpage()
{
	free();
}

Webpage& Webpage::operator=(const Webpage& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

char* Webpage::getAdress() const
{
	return adress;
}

size_t Webpage::getAdressLen() const
{
	return adressLen;
}

char* Webpage::getIp() const
{
	return ip;
}

size_t Webpage::getIpLen() const
{
	return ipLen;
}

std::ostream& operator<<(std::ostream& os, const Webpage& wp)
{
	return os << "Adress: " << wp.adress << std::endl << "Ip: " << wp.ip;
}

std::istream& operator>>(std::istream& is, Webpage& wp)
{
	wp.free();
	char buff[1024];
	is >> buff;
	wp.adressLen = strlen(buff);
	wp.adress = new char[wp.adressLen + 1];
	strcpy(wp.adress, buff);
	char buff2[1024];
	is >> buff2;
	wp.ipLen = strlen(buff2);
	wp.ip = new char[wp.ipLen + 1];
	strcpy(wp.ip, buff2);
	return is;
}
