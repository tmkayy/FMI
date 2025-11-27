//#include "MyString.h"
//#pragma warning (disable : 4996)
//
//MyString::MyString() : MyString("") {
//
//}
//
//MyString::MyString(const char* data) {
//	size = strlen(data);
//	capacity = calculateCapacity(size);
//	this->data = new char[capacity];
//	strcpy(this->data, data);
//}
//
//MyString::MyString(const MyString& other) {
//	copyFrom(other);
//}
//MyString& MyString::operator= (const MyString& other) {
//	if (this != &other) {
//		free();
//		copyFrom(other);
//	}
//}
//MyString::~MyString() {
//	free();
//}
//
//size_t MyString::getSize() const {
//	return size;
//}
//size_t MyString::getCapacity() const {
//	return capacity;
//}
//const char* MyString::c_str() const {
//	return data;
//}
//
//MyString MyString::substr(unsigned begin, unsigned offset) const {
//	char* newData = data;
//	newData += begin;
//	char* ptr = new char[offset - begin + 1];
//	strncpy(newData, ptr, offset);
//
//	MyString s(newData);
//
//	delete[] newData;
//	return s;
//}
//
//MyString& MyString::operator+=(const MyString& other) {
//	if (other.size + size > capacity)
//	{
//		resize(calculateCapacity(other.size + size));
//	}
//	strncat(data, other.data, other.size);
//	size += other.size;
//	return *this;
//}
//
//char& MyString::operator[](unsigned indx) {
//	char error = ' ';
//	if (indx > size)
//		return error;
//
//	return data[indx];
//}
//const char& MyString::operator[](unsigned indx) const {
//	char error = ' ';
//	if (indx > size)
//		return error;
//
//	return data[indx];
//}
//
//MyString operator+(const MyString& lhs, const MyString& rhs) {
//	MyString result(lhs);
//	result += rhs;
//	return result;
//}
//std::ostream& operator<<(std::ostream& os, const MyString str) {
//	return os << str.data;
//}
//std::istream& operator>>(std::istream& is, MyString str) {
//	char buff[1024];
//	is >> buff;
//
//	size_t buffSize = strlen(buff);
//	str.capacity = calculateCapacity(buffSize);
//	delete[] str.data;
//	str.data = new char[str.capacity];
//	str.size = buffSize;
//	strncpy(str.data, buff, buffSize);
//}
//
//void MyString::free() {
//	delete[] data;
//	data = nullptr;
//	size = 0;
//	capacity = 0;
//}
//void MyString::copyFrom(const MyString& other) {
//	size = other.size;
//	capacity = other.capacity;
//	data = new char[capacity];
//	strncpy(data, other.data, size);
//}
//void MyString::resize(unsigned char howMany) {
//	char* newData = new char[howMany];
//	strcpy(data, newData);
//	delete[] data;
//	data = newData;
//	capacity += 16;
//}
//
//size_t calculateCapacity(unsigned v) {
//	return ((v / 16) + 1) * 16;
//}
//
//bool operator==(const MyString& lhs, const MyString& rhs) {
//	return strcmp(lhs.c_str(), rhs.c_str());
//}
//bool operator!=(const MyString& lhs, const MyString& rhs);
//bool operator>(const MyString& lhs, const MyString& rhs);
//bool operator>=(const MyString& lhs, const MyString& rhs);
//bool operator<(const MyString& lhs, const MyString& rhs);
//bool operator<=(const MyString& lhs, const MyString& rhs);
//bool operator!=(const MyString& lhs, const MyString& rhs);