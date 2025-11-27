//#include "MyVector.h"
//
//void MyVector::free()
//{
//	delete[] data;
//}
//
//void MyVector::copyFrom(const MyVector& other)
//{
//	size = other.size;
//	capacity = other.capacity;
//	data = new MyString[capacity];
//	for (size_t i = 0; i < size; i++)
//	{
//		data[i] = other.data[i];
//	}
//}
//
//void MyVector::resize(size_t capacity)
//{
//	size_t newCpacity = nextPowerOf2Two(capacity + 1);
//	MyString* newData = new MyString[newCpacity];
//	for (size_t i = 0; i < capacity; i++)
//	{
//		newData[i] = data[i];
//	}
//	delete[] data;
//	data = newData;
//	capacity = newCpacity;
//}
//
//size_t MyVector::nextPowerOf2Two(size_t capacity)
//{
//	capacity |= capacity >> 1;
//	capacity |= capacity >> 2;
//	capacity |= capacity >> 4;
//	capacity |= capacity >> 8;
//	capacity |= capacity >> 16;
//	capacity |= capacity >> 32;
//	++capacity;
//	return capacity;
//}
//
//MyVector::MyVector()
//{
//	capacity = std::max(nextPowerOf2Two(size), (size_t)16);
//	size = 0;
//	data = new MyString[capacity];
//}
//
//MyVector::MyVector(size_t size)
//{
//	size = 0;
//	capacity = 16;
//	data = new MyString[capacity];
//}
//
//MyVector::MyVector(const MyVector& other)
//{
//	copyFrom(other);
//}
//
//MyVector::~MyVector()
//{
//	free();
//}
//
//MyVector& MyVector::operator=(const MyVector& other)
//{
//	if (this != &other) {
//		free();
//		copyFrom(other);
//	}
//	return *this;
//}
//
//void MyVector::push_back(const MyString& obj)
//{
//	if (size == capacity) {
//		resize(nextPowerOf2Two(size + 1));
//	}
//	data[size++] = obj;
//}
//
//void MyVector::pop_back(const MyString& obj)
//{
//	delete& data[--size];
//}
//
//void MyVector::shrinkToFit()
//{
//	size_t newCpacity = nextPowerOf2Two(capacity + 1);
//	MyString* newData = new MyString[newCpacity];
//	for (size_t i = 0; i < capacity; i++)
//	{
//		newData[i] = data[i];
//	}
//	delete[] data;
//	data = newData;
//	capacity = newCpacity;
//
//}
//
//size_t MyVector::getSize() const
//{
//	return size;
//}
//
//const MyString& MyVector::operator[](size_t idx) const
//{
//	return data[idx];
//}
//
//MyString& MyVector::operator[](size_t idx)
//{
//	return data[idx];
//}
//
//void MyVector::insert(size_t idx, const MyString& el)
//{
//	if (idx > size)
//		return;
//	if (size == capacity)
//		resize(nextPowerOf2Two(size + 1));
//	for (int i = size - 1; i >= idx; i--)
//	{
//		data[i + 1] = data[i];
//	}
//	data[idx] = el;
//	size++;
//}
//
//void MyVector::erase(size_t idx)
//{
//	if (idx > size || idx < 0)
//		return;
//	for (size_t i = capacity; i < size - 1; i++)
//	{
//		data[i] = data[i + 1];
//	}
//	size--;
//}
//
//void MyVector::clear()
//{
//	size = 0;
//}
//
//bool MyVector::empty() const
//{
//	return size == 0;
//}
