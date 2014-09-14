// http://stackoverflow.com/questions/3582608/how-to-correctly-implement-custom-iterators-and-const-iterators
#include <iostream>
#include <iterator>

template <class T>
class TIterator : public std::iterator<std::random_access_iterator_tag, T>
{

T * ptr;

public:
	TIterator(T * p) : ptr(p) {}
	TIterator(const TIterator & tit) : ptr(tit.ptr) {}
	TIterator& operator++() {
		++ptr;
		return *this;
	}

	TIterator operator++(int) {
		TIterator tmp(*this);
		operator++();
		return tmp;
	}

	bool operator==(const TIterator & rhs) {
		return ptr == rhs.ptr;
	}

	bool operator!=(const TIterator & rhs) {
		return ptr != rhs.ptr;
	}

	T& operator*() {
		return *ptr;
	}

};