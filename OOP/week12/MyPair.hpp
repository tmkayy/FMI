template <typename U, typename V>
class MyPair {
	U u;
	V v;
public:
	MyPair(const U& u, const V& v);
	void setU(const U& u);
	void setV(const V& v);
	const U& getU() const;
	const V& getV() const;

	friend bool operator==(const MyPair<U, V>& lhs, const MyPair<U, V>& rhs);
	friend bool operator!=(const MyPair<U, V>& lhs, const MyPair<U, V>& rhs);
	friend bool operator<(const MyPair<U, V>& lhs, const MyPair<U, V>& rhs);
};

template<typename U, typename V>
inline MyPair<U, V>::MyPair(const U& u, const V& v)
{
	setU(u);
	setV(v);
}

template<typename U, typename V>
inline void MyPair<U, V>::setU(const U& u)
{
	this->u = u;
}

template<typename U, typename V>
inline void MyPair<U, V>::setV(const V& v)
{
	this->v = v;
}

template<typename U, typename V>
inline const U& MyPair<U, V>::getU() const
{
	return u;
}

template<typename U, typename V>
inline const V& MyPair<U, V>::getV() const
{
	return v;
}
