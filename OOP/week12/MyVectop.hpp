#include <stdexcept>

template <typename T>
class MyVector {
	T* data;
	size_t size;
	size_t capacity;

	void free();
	void copyFrom(const MyVector<T>& other);
	void moveFrom(MyVector<T>&& other);
	void resize();
public:
	MyVector();
	MyVector(size_t n);
	MyVector(size_t n, const T& elem);

	~MyVector();
	MyVector(const MyVector<T>& other);
	MyVector<T>& operator=(const MyVector<T>& other);

	MyVector(MyVector<T>&& other);
	MyVector<T>& operator=(MyVector<T>&& other);

	void push_back(const T& elem);
	void push_back(T&& elem);
	void pop_back();
	void insert(size_t idx, const T& elem);
	void insert(size_t idx, T&& elem);
	void erase(size_t idx);
	T& operator[](size_t idx);
	const T& operator[](size_t idx) const;
	void shrink_to_fit();
	void clear();
	const T& front() const;
	T& front();
	const T& back() const;
	T& back();
	void empty();
	size_t size() const;
	size_t capacity() const;
};

template<typename T>
inline void MyVector<T>::free()
{
	delete[] data;
	capacity = size = 0;
	data = nullptr;
}

template<typename T>
inline void MyVector<T>::copyFrom(const MyVector<T>& other)
{
	capacity = other.capacity;
	size = other.size;
	data = new T[capacity];
	for (size_t i = 0; i < capacity; i++)
	{
		data = other.data[i];
	}
}

template<typename T>
inline void MyVector<T>::moveFrom(MyVector<T>&& other)
{
	data = other.data;
	capacity = other.capacity;
	size = other.size;

	other.size = 0;
	other.capacity = 0;
}

template<typename T>
inline void MyVector<T>::resize()
{
	T* newData = new T[capacity * 2];
	for (size_t i = 0; i < capacity; i++)
	{
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
	capacity *= 2;
}

template<typename T>
inline MyVector<T>::MyVector()
{
	size = 0;
	capacity = 0;
	data = nullptr;
}

template<typename T>
inline MyVector<T>::MyVector(size_t n)
{
	size = n;
	capacity = n;
	data = new T[capacity];
}

template<typename T>
inline MyVector<T>::MyVector(size_t n, const T& elem)
{
	size = n;
	capacity = n;
	data = new T[capacity];
	for (size_t i = 0; i < capacity; i++)
	{
		data[i] = elem;
	}
}

template<typename T>
inline MyVector<T>::~MyVector()
{
	free();
}

template<typename T>
inline MyVector<T>::MyVector(const MyVector<T>& other)
{
	copyFrom(other);
}

template<typename T>
inline MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other)
{
	if (this != other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
inline MyVector<T>::MyVector(MyVector<T>&& other)
{
	moveFrom(std::move(other));
}

template<typename T>
inline MyVector<T>& MyVector<T>::operator=(MyVector<T>&& other)
{
	if (this != other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<typename T>
inline void MyVector<T>::push_back(const T& elem)
{
	if (size == capacity)
		resize();
	data[size++] = elem;
}

template<typename T>
inline void MyVector<T>::push_back(T&& elem)
{
	if (size == capacity)
		resize();
	data[size++] = std::move(elem);
}

template<typename T>
inline void MyVector<T>::pop_back()
{
	delete data[--size];
}

template<typename T>
inline void MyVector<T>::insert(size_t idx, const T& elem)
{
	if (i<0 || i>size) {
		throw std::invalid_argument("no");
	}
	if (size == capacity) {
		resize();
	}
	size++;
	for (int i = size - 1; i >= idx; i--)
	{
		data[i] = data[i - 1];
	}
	data[idx] = elem;
}

template<typename T>
inline void MyVector<T>::insert(size_t idx, T&& elem)
{
	if (i<0 || i>size) {
		throw std::invalid_argument("no");
	}
	if (size == capacity) {
		resize();
	}
	size++;
	for (int i = size - 1; i >= idx; i--)
	{
		data[i] = data[i - 1];
	}
	data[idx] = std::move(elem);
}

template<typename T>
inline void MyVector<T>::erase(size_t idx)
{
	if (i<0 || i>size) {
		throw std::invalid_argument("no");
	}
	delete data[idx];
	for (size_t i = idx; i < size; i++)
	{
		data[i] = data[i + 1];
	}
	size--;
}

template<typename T>
inline T& MyVector<T>::operator[](size_t idx)
{
	return data[idx];
}

template<typename T>
inline const T& MyVector<T>::operator[](size_t idx) const
{
	return data[idx];
}

template<typename T>
inline void MyVector<T>::shrink_to_fit()
{
	T* newData = new T[size];
	for (size_t i = 0; i < size; i++)
	{
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
	capacity = size;
}

template<typename T>
inline void MyVector<T>::clear()
{
	delete[] data;
	size = 0;
}

template<typename T>
inline const T& MyVector<T>::front() const
{
	return data[0];
}

template<typename T>
inline T& MyVector<T>::front()
{
	return data[0];
}

template<typename T>
inline const T& MyVector<T>::back() const
{
	return data[size];
}

template<typename T>
inline T& MyVector<T>::back()
{
	return data[size];
}

template<typename T>
inline void MyVector<T>::empty()
{
	free();
}

template<typename T>
inline size_t MyVector<T>::size() const
{
	return size;
}

template<typename T>
inline size_t MyVector<T>::capacity() const
{
	return capacity;
}
