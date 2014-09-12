#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>
#include <vector>

template <typename T> class Vector : public std::iterator<random_access_iterator_tag, T>{
	

public:
	// typedef T value_type;
	// typedef typename std::vector<T>::size_type size_type;
	typedef Vector<T*> iterator;
	typedef Vector<const T*> const_iterator;

	static_assert(std::is_move_constructible<T>::value, "type requires move constructable");
	static_assert(std::is_move_assignable<T>::value, "type requires move assignable");

	// constructors
	Vector();
	Vector(std::size_t);
	Vector(std::initializer_list<T>);
	Vector(std::size_t, T);

	// destructor
	~Vector();

	// operators
	T& operator[] (const int index);

	// functions
	std::size_t size() const {
		return _size;
	}

	void push_back(T e) {
		if (_size >= _capacity) {
			increase_capacity(2 * _capacity);
		}
		_arr[_size++] = e;
	}
	
	void insert(std::size_t i, T e) {
		if (i < 0 || i > _size) {
			throw std::out_of_range("index of out range");
		}

		push_back(0);

		// move all elements from index i one position to the right
		for (int j = _size - 1; j > i; j--) {
			_arr[j] = _arr[j - 1];
		}

		_arr[i] = e;
	}

	void clear() {
		_size = 0;
		_capacity = 10;
		delete[] _arr;
		_arr = new T[_capacity];
	}

	// TODO
	void erase(std::size_t i) {
		if (i < 0 || i >= _size) {
			throw std::out_of_range("index of out range");
		}

		for (i; i < _size; i++) {
			_arr[i] = _arr[i + 1];
		}

		_size--;
	}

	std::size_t capacity() const {
		return _capacity;
	}

	iterator begin() {
		return iterator(_arr[i]);
	}

	iterator end() {
		return iterator(_arr[_size]);
	}

private:
	T * _arr; // pointer to the first element of the vector
	std::size_t _capacity; // number of elements the vector can hold
	std::size_t _size; // size of the vector

	//functions
	void increase_capacity(std::size_t new_capacity) {
		if (new_capacity <= _capacity) return;

		T * new_arr = new T[new_capacity];
		for (int i = 0; i < _capacity; i++) {
			new_arr[i] = _arr[i];
		}

		_capacity = new_capacity;

		delete[] _arr;
		_arr = new_arr;
	}

};

template <typename T>
Vector<T>::Vector() : _size(0), _capacity(10) {
	std::cout << "default constructor" << std::endl;
	_arr = new T[_capacity];
}

template <typename T>
Vector<T>::Vector(std::size_t size) : _size(size), _capacity(size * 2) {
	_arr = new T[_capacity];

	for (int i = 0; i < _capacity; i++){
		_arr[i] = 0;
	}
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> args) : _size(args.size()), _capacity(args.size()*2) {

	_arr = new T[_capacity];
	int i = 0;
	for (auto iter = args.begin(); iter != args.end(); ++iter) {
		_arr[i++] = *iter;
	}
}

template <typename T>
Vector<T>::Vector(std::size_t size, T init) : _size(size), _capacity(size * 2) {
	_arr = new T[_capacity];
	for (int i = 0; i < _capacity; i++) {
		_arr[i] = init;
	}
}


template <typename T>
Vector<T>::~Vector() {
	delete[] _arr;
}

template <typename T>
T& Vector<T>::operator[] (const int index) {

	if (index < 0 || index >= _size) {
		throw std::out_of_range("out of range");
	}

	return _arr[index];
}

#endif