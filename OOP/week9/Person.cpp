#include "Person.h"
#include <string>;
#include <stdexcept>;

void Person::copyFrom(const Person& other) {
	setName(other.name);
	setAge(other.age);
}
void Person::free() {
	delete[] name;
}
void Person::moveFrom(Person&& other) {
	name = other.name;
	age = other.age;
	other.name = nullptr;
}

Person::Person(const char* name, int age) {
	setName(name);
	setAge(age);
}
Person::Person(const Person& other) {
	copyFrom(other);
}
Person& Person::operator=(const Person& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
Person::~Person() {
	free();
}

Person::Person(Person&& other) {
	moveFrom(std::move(other));
}
Person& Person::operator=(Person&& other) {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

void Person::setName(const char* name) {
	if (!name || this->name == name)
		throw std::invalid_argument("invalid name");

	delete[] name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
void Person::setAge(int age) {
	if(age<0)
		throw std::invalid_argument("invalid age");

	this->age = age;
}

const char* Person::getName() const {
	return name;
}
int Person::getAge() const {
	return age;
}