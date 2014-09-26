// http://stackoverflow.com/questions/3582608/how-to-correctly-implement-custom-iterators-and-const-iterators
#include <iostream>
#include <iterator>

template <class T>
class VectorIterator : public std::iterator<std::random_access_iterator_tag, T>
{

T * ptr;

public:
	VectorIterator(T * p) : ptr(p) {}
	VectorIterator(const VectorIterator & tit) : ptr(tit.ptr) {}
	VectorIterator& operator++() {
		++ptr;
		return *this;
	}

	VectorIterator operator++(int) {
		VectorIterator tmp(*this);
		operator++();
		return tmp;
	}

	bool operator==(const VectorIterator & rhs) {
		return ptr == rhs.ptr;
	}

	bool operator!=(const VectorIterator & rhs) {
		return ptr != rhs.ptr;
	}

	T& operator*() {
		return *ptr;
	}

};