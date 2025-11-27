template <typename T>
class Stack {
	T* data;
	size_t size;
	size_t capacity;

	void free();
	void copyFrom(const Stack<T>& other);
	void moveFrom(Stack<T>&& other);
	void resize();

public:
	Stack();
	Stack(const Stack<T>& other);
	~Stack();
	Stack<T>& operator= (const Stack<T>& other);

	Stack(Stack<T>&& other);
	Stack<T>& operator= (Stack<T>&& other);

	void push(const T& elem);
	void push(T&& elem);
	void pop();
	const T& top() const;
	bool empty() const;
	size_t size() const;
};

template<typename T>
inline void Stack<T>::free()
{
	delete[] data;
	capacity = size = 0;
}

template<typename T>
inline void Stack<T>::copyFrom(const Stack<T>& other)
{
	capacity = other.capacity;
	size = other.size;
	data = new T[capacity];
	for (size_t i = 0; i < capacity; i++)
	{
		data[i] = other.data[i];
	}
}

template<typename T>
inline void Stack<T>::moveFrom(Stack<T>&& other)
{
	data = other.data;
	capacity = other.capacity;
	size = other.size;

	other.data = nullptr;
	other.capacity = other.size = 0;
}

template<typename T>
inline void Stack<T>::resize()
{
	T* newData = T(capacity * 2);
	for (size_t i = 0; i < capacity; i++)
	{
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
	capacity *= 2;
}

template<typename T>
inline Stack<T>::Stack()
{
	data = 0;
	size = 0;
	capacity = 8;
}

template<typename T>
inline Stack<T>::Stack(const Stack<T>& other)
{
	copyFrom(other);
}

template<typename T>
inline Stack<T>::~Stack()
{
	free();
}

template<typename T>
inline Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
	if (this != other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
inline Stack<T>::Stack(Stack<T>&& other)
{
	moveFrom(std::move(other));
}

template<typename T>
inline Stack<T>& Stack<T>::operator=(Stack<T>&& other)
{
	if (this != other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}
