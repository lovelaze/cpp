#include <initializer_list>
#include <stdexcept>
#include <iostream>
#include <type_traits>

template <class T>
class Vector {
	static_assert(std::is_move_constructible<T>::value,  "Type must be move_constructible");
	static_assert(std::is_move_assignable<T>::value,  "Type must be move_assignable");

private:
	std::size_t size_array; // size of the vector
	std::size_t cap_array; // number of elements the vector can hold
	T * array; // pointer to the first element of the vector

	//functions
	void increase_capacity(std::size_t new_capacity);
	
public:
	typedef T* iterator;
	typedef const T* const_iterator;

	// constructors
	Vector();
	explicit Vector(std::size_t);
	Vector(const std::initializer_list<T>);
	Vector(const std::size_t, const T);
	Vector(const Vector<T> &);
	Vector(Vector<T> &&);

	// destructor
	~Vector();

	// operators
	T& operator[] (const std::size_t index);
	const T& operator[] (const std::size_t index) const;

	Vector<T> & operator= (const Vector<T> & src);
	Vector<T> & operator= (Vector<T> && other);


	// functions
	std::size_t size() const;
	void push_back(const T value);
	void insert(const std::size_t index , const T value);
	void clear();
	void erase(const std::size_t i);
	std::size_t capacity() const;
	void print() const ;
	void reset();

	iterator begin();
	iterator end();
	iterator find(const T &);

	const_iterator begin() const;
	const_iterator end() const;
	const_iterator find(const T &) const;

};


// default constructor
template <class T>
Vector<T>::Vector() : size_array(0), cap_array(10), array(new T[cap_array]) {
}

// constructor : size
template <class T>
Vector<T>::Vector(std::size_t size) : size_array(size), cap_array(size * 2), array(new T[cap_array]) {

	for (std::size_t i = 0; i < cap_array; ++i){
		array[i] = T();
	}
}

// constructor : initalizer_list 
template <class T>
Vector<T>::Vector(const std::initializer_list<T> args) : size_array(args.size()), cap_array(args.size()*2), array(new T[cap_array]) {
	int i = 0;
	for (auto iter = args.begin(); iter != args.end(); ++iter) {
		array[i] = *iter;
		++i;
	}
}

// constructor : size, init value
template <class T>
Vector<T>::Vector(const std::size_t size, const T init) : size_array(size), cap_array(size * 2), array(new T[cap_array]) {
	for (std::size_t i = 0; i < cap_array; ++i) {
		array[i] = init;
	}
}

// copy constructor
template <class T>
Vector<T>::Vector(const Vector<T> & src) : size_array(src.size_array), cap_array(src.cap_array), array(new T[cap_array]) {
	for (std::size_t i = 0; i != size_array; ++i) {
		array[i] = src.array[i];
	}
}


// move constructor
template <class T>
Vector<T>::Vector(Vector<T> && other) : size_array(other.size_array), cap_array(other.cap_array), array(other.array){
	other.size_array = 0;
	other.cap_array = 0;
	other.array = nullptr;
}

// destructor
template <class T>
Vector<T>::~Vector() {
	delete [] array;
}

// subscript operator
template <class T>
T& Vector<T>::operator[] (const std::size_t index) {

	if (index < 0 || index >= size_array) {
		throw std::out_of_range("out of range");
	}

	return array[index];
}

// subscript operator
template <class T>
const T& Vector<T>::operator[] (const std::size_t index) const{

	if (index < 0 || index >= size_array) {
		throw std::out_of_range("out of range");
	}

	return array[index];
}

// assignment
template <class T>
Vector<T> & Vector<T>::operator= (const Vector<T> & src) {

	if (&src != this) {

		size_array = src.size_array;
		cap_array = src.cap_array;
		T * new_array = new T[cap_array];

		for (std::size_t i = 0; i != size_array; ++i) {
			new_array[i] = src.array[i];
		}

		delete [] array;

		array = new_array;

	}

	return *this;

}

// assignment move
template <class T>
Vector<T> & Vector<T>::operator= (Vector<T> && other) {
	if (&other != this) {
		delete [] array;
		array = other.array;
		size_array = other.size_array;

		other.array = nullptr;
		other.size_array = 0;
	}

	return *this;
}


// functions
template <class T>
std::size_t Vector<T>::size() const {
	return size_array;
}

template <class T>
void Vector<T>::push_back(const T e) {
	if (cap_array == 0 && size_array == 0) {
		increase_capacity(20);
	}
	if (cap_array == 0 && size_array != 0) {
		increase_capacity(size_array*2);
	}
	if (size_array >= cap_array) {
		increase_capacity(2 * cap_array);
	}
	array[size_array] = e;
	++size_array;
}

template <class T>
void Vector<T>::insert(const std::size_t i, const T e) {
	if (i < 0 || i > size_array) {
		throw std::out_of_range("index of out range");
	}
	push_back(T()); // "make space" to move elements

	// move all elements from index i one position to the right
	for (std::size_t j = size_array - 1; j > i; --j) {
		array[j] = array[j - 1];
	}
	array[i] = e;
}

template <class T>
void Vector<T>::clear() {
	size_array = 0;
	T * new_arr = new T[cap_array];
	delete[] array;
	array = new_arr;
}

template <class T>
void Vector<T>::erase(const std::size_t i) {
	if (i < 0 || i >= size_array) {
		throw std::out_of_range("index of out range");
	}
	
	for (std::size_t j = i; j < size_array; ++j) {
		array[j] = array[j + 1];
		
	}
	--size_array;

}

template <class T>
std::size_t Vector<T>::capacity() const {
	return cap_array;
}

template <class T>
void Vector<T>::print() const {
	if(size_array == 0) {
		std::cout << "{} : size_array = " << size_array << ", cap_array = " << cap_array << std::endl;
	} else {
		std::cout << "{";
		for (size_t i = 0; i < cap_array - 1; ++i) {
			if ( i == size_array-1) {
				std::cout << array[i] << " | ";
			} else {
				std::cout << array[i] << ", ";	
			}
			
		}
		std::cout << array[size_array - 1] << "} : size_array = " << size_array << ", cap_array = " << cap_array << std::endl;
	}
}

template <class T>
void Vector<T>::increase_capacity(std::size_t new_capacity) {
	if (new_capacity <= cap_array) {
		throw std::range_error("Can't decrease the capacity");
		return;
	}

	T * new_arr = new T[new_capacity];
	for (std::size_t i = 0; i < size_array; ++i) {
		new_arr[i] = array[i];
	}

	cap_array = new_capacity;

	delete[] array;
	array = new_arr;
}

template <class T>
void Vector<T>::reset() {
	for (std::size_t i = 0; i != size_array; ++i) {
		array[i] = T();
	}
}

template <class T>
typename Vector<T>::iterator Vector<T>::begin() {
	return array;
}

template <class T>
typename Vector<T>::iterator Vector<T>::end() {
	return array+size_array;
}

template <class T>
typename Vector<T>::iterator Vector<T>::find(const T & ref) {
	for (auto it = begin(); it != end(); ++it) {
		if (ref == *it) {
			return it;
		}
	}

	return end();
}

template <class T>
typename Vector<T>::const_iterator Vector<T>::begin() const {

	return array;
}

template <class T>
typename Vector<T>::const_iterator Vector<T>::end() const {
	return array+size_array;
}

template <class T>
typename Vector<T>::const_iterator Vector<T>::find(const T & ref) const {
	for (auto it = begin(); it != end(); ++it) {
		if (ref == *it) {
			return it;
		}
	}

	return end();
}
