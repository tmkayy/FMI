#include "MyPair.hpp"

template <typename U, typename V>
bool operator==(const MyPair<U, V>& lhs, const MyPair<U, V>& rhs)
{
	return (lhs.getU() == rhs.getU())
		&& (rhs.getV() == rhs.getV());
}

template <typename U, typename V>
bool operator!=(const MyPair<U, V>& lhs, const MyPair<U, V>& rhs)
{
	return !(operator==(lhs, rhs));
}

template <typename U, typename V>
bool operator<(const MyPair<U, V>& lhs, const MyPair<U, V>& rhs)
{
	return (lhs.getU() < rhs.getU())
		&& (rhs.getV() < rhs.getV());
}
