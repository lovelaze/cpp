// http://stackoverflow.com/questions/3582608/how-to-correctly-implement-custom-iterators-and-const-iterators
#include <iostream>
#include <iterator>

template <class T>
class VectorIterator : public std::iterator<std::random_access_iterator_tag, T> {

private:
	T * ptr;

public:
	typedef VectorIterator self_type;
	typedef T value_type;
	typedef T& reference;
	typedef T* pointer;
	typedef std::random_access_iterator_tag iterator_category;
	typedef int difference_type;

	VectorIterator(pointer ptr) : ptr(ptr) { }

	self_type operator++() {
		self_type i = *this;
		ptr++;
		return i;
	}
	self_type operator++(int yolo) {
		ptr++;
		return *this;
	}

	self_type operator--() {
		self_type i = *this;
		ptr--;
		return i;
	}
	self_type operator--(int yolo) {
		ptr--;
		return *this;
	}


	self_type operator+(const std::size_t i) {
		ptr += i;
		return *this;
	}

	self_type operator+=(const std::size_t i) {
		ptr += i;
		return *this;
	}

	self_type operator-(const std::size_t i) {
		ptr -= i;
		return *this;
	}

	self_type operator-=(const std::size_t i) {
		ptr -= i;
		return *this;
	}

	// NOT WORKING
	/*
	self_type operator-(const self_type & rhs) {
		std::cout << "ptr = " << ptr << std::endl;
		std::cout << "rhs.ptr = " << rhs.ptr << std::endl;
		//ptr= ptr - rhs.ptr;
		return *this;
	}*/


	reference operator*() {
		return *ptr;
	}

	pointer operator->() {
		return ptr;
	}

	const reference operator*() const {
		return *ptr;
	}

	const pointer operator->() const {
		return ptr;
	}

	bool operator==(const self_type & rhs) {
		return ptr == rhs.ptr;
	}

	bool operator!=(const self_type & rhs) {
		return ptr != rhs.ptr;
	}

	bool operator>(const self_type & rhs) {
		return ptr > rhs.ptr;
	}

	bool operator>=(const self_type & rhs) {
		return ptr >= rhs.ptr;
	}

	bool operator<(const self_type & rhs) {
		return ptr < rhs.ptr;
	}

	bool operator<=(const self_type & rhs) {
		return ptr <= rhs.ptr;
	}

};