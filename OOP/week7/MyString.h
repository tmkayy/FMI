//#pragma once
//#include <iostream>
//
//class MyString
//{
//	char* data;
//	size_t size;
//	size_t capacity;
//
//public:
//	MyString();
//	MyString(const char* data);
//	MyString(const MyString& other);
//	MyString& operator= (const MyString& other);
//	~MyString();
//
//	size_t getSize() const;
//	size_t getCapacity() const;
//	const char* c_str() const;
//
//	MyString substr(unsigned begin, unsigned offset) const;
//
//	MyString& operator+=(const MyString& other);
//
//	char& operator[](unsigned indx);
//	const char& operator[](unsigned indx) const;
//
//	friend MyString operator+(const MyString& lhs, const MyString& rhs);
//	friend std::ostream& operator<<(std::ostream& os, const MyString str);
//	friend std::istream& operator>>(std::istream& is, MyString str);
//
//private:
//	void free();
//	void copyFrom(const MyString& other);
//	void resize(unsigned char howMany);
//	static size_t calculateCapacity(unsigned v);
//};
//
//bool operator==(const MyString& lhs, const MyString& rhs);
//bool operator!=(const MyString& lhs, const MyString& rhs);
//bool operator>(const MyString& lhs, const MyString& rhs);
//bool operator>=(const MyString& lhs, const MyString& rhs);
//bool operator<(const MyString& lhs, const MyString& rhs);
//bool operator<=(const MyString& lhs, const MyString& rhs);
//bool operator!=(const MyString& lhs, const MyString& rhs);
//
