#pragma once
class Person
{
	char* name;
	unsigned age;

	void copyFrom(const Person& other);
	void free();
	void moveFrom(Person&& other);

public:
	Person() = delete;
	Person(const char* name, int age);
	Person(const Person& other);
	Person& operator=(const Person& other);
	~Person();

	Person(Person&& other);
	Person& operator=(Person&& other);

	void setName(const char* name);
	void setAge(int age);

	const char* getName() const;
	int getAge() const;
};

