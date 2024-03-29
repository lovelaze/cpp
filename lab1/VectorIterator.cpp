// http://stackoverflow.com/questions/3582608/how-to-correctly-implement-custom-iterators-and-const-iterators
#include <iostream>
#include <iterator>

template <class T>
class VectorIterator : public std::iterator<std::random_access_iterator_tag, T, std::ptrdiff_t, T*, T&> {

	typedef VectorIterator<T> self_type;
	typedef T value_type;
	typedef T& reference;
	typedef T* pointer;
	typedef std::random_access_iterator_tag iterator_category;
	typedef std::ptrdiff_t difference_type;

private:
	pointer ptr;

public:
	VectorIterator(pointer ptr = nullptr) : ptr(ptr) { }
	VectorIterator(const self_type & src) = default;
	~VectorIterator() { }

	

	self_type operator++() {
		self_type i = *this;
		++ptr;
		return i;
	}
	self_type operator++(int yolo) {
		++ptr;
		return *this;
	}

	self_type operator--() {
		self_type i = *this;
		--ptr;
		return i;
	}
	self_type & operator--(int yolo) {
		--ptr;
		return *this;
	}


	self_type & operator+(const difference_type i) {
		ptr += i;
		return *this;
	}

	self_type & operator+=(const difference_type i) {
		ptr += i;
		return *this;
	}

	self_type & operator-=(const difference_type i) {
		ptr -= i;
		return *this;
	}

	self_type operator-(const difference_type & diff){
		std::cerr << "operator-(const difference_type & diff)" << std::endl;
		auto oldPtr = ptr;
		ptr -= diff;
		auto temp(*this);
		ptr = oldPtr;
		return temp;
	}

	difference_type operator-(const self_type & rhs){
		std::cerr << "operator-(const self_type & rhs)" << std::endl;
		return std::distance(rhs.ptr, ptr);
	}




	reference operator*() {
		return *ptr;
	}
	const reference operator*() const {
		return *ptr;
	}

	pointer operator->() {
		return ptr;
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