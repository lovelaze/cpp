
// default constructor
template <class T>
Vector<T>::Vector() : _size(0), _capacity(10) {
	_arr = new T[_capacity];
}

// constructor : size
template <class T>
Vector<T>::Vector(std::size_t size) : _size(size), _capacity(size * 2) {
	_arr = new T[_capacity];

	for (std::size_t i = 0; i < _capacity; ++i){
		_arr[i] = T();
	}
}

// constructor : initalizer_list 
template <class T>
Vector<T>::Vector(const std::initializer_list<T> args) : _size(args.size()), _capacity(args.size()*2) {
	_arr = new T[_capacity];
	int i = 0;
	for (auto iter = args.begin(); iter != args.end(); ++iter) {
		_arr[i] = *iter;
		++i;
	}
}

// constructor : size, init value
template <class T>
Vector<T>::Vector(std::size_t size, T init) : _size(size), _capacity(size * 2) {
	_arr = new T[_capacity];
	for (int i = 0; i < _capacity; ++i) {
		_arr[i] = init;
	}
}

// copy constructor TODO
template <class T>
Vector<T>::Vector(const Vector<T> & src) : _size(src._size), _capacity(src._capacity), _arr(new T[_capacity]) {
	for (std::size_t i = 0; i != _size; ++i) {
		_arr[i] = src._arr[i];
	}

}


// move constructor TODO
template <class T>
Vector<T>::Vector(Vector<T> && other) : _size(0), _capacity(10), _arr(NULL){
	_size = other._size;
	_capacity = other._capacity;
	_arr = other._arr;

	other._size = 0;
	other._capacity = 0;
	other._arr = NULL;
}

// destructor
template <class T>
Vector<T>::~Vector() {
	delete [] _arr;
}

// subscript operator
template <class T>
T& Vector<T>::operator[] (const std::size_t index) {

	if (index < 0 || index >= _size) {
		throw std::out_of_range("out of range");
	}

	return _arr[index];
}

// subscript operator
template <class T>
const T& Vector<T>::operator[] (const std::size_t index) const{

	if (index < 0 || index >= _size) {
		throw std::out_of_range("out of range");
	}

	return _arr[index];
}

// assignment
template <class T>
Vector<T> & Vector<T>::operator= (const Vector<T> & src) {

	if (&src != this) {

		_size = src._size;
		_capacity = src._capacity;
		T * new_array = new T[_capacity];

		for (std::size_t i = 0; i != _size; ++i) {
			new_array[i] = src._arr[i];
		}

		delete [] _arr;

		_arr = new_array;

	}

	return *this;

}

template <class T>
Vector<T> & Vector<T>::operator= (Vector<T> && other) {
	if (&other != this) {
		delete [] _arr;
		_arr = other._arr;
		_size = other._size;

		other._arr = NULL;
		other._size = 0;
	}

	return *this;
}


// functions
template <class T>
std::size_t Vector<T>::size() const {
	return _size;
}

template <class T>
void Vector<T>::push_back(const T e) {
	if (_size >= _capacity) {
		increase_capacity(2 * _capacity);
	}
	_arr[_size] = e;
	++_size;
}

template <class T>
void Vector<T>::insert(const std::size_t i, const T e) {
	if (i < 0 || i > _size) {
		throw std::out_of_range("index of out range");
	}
	push_back(e); // "make space" to move elements

	// move all elements from index i one position to the right
	for (int j = _size - 1; j > i; j--) {
		_arr[j] = _arr[j - 1];
	}
	_arr[i] = e;
}

template <class T>
void Vector<T>::clear() {
	_size = 0;
	_capacity = 10;
	T * new_arr = new T[_capacity];
	delete[] _arr;
	_arr = new_arr;
}

template <class T>
void Vector<T>::erase(const std::size_t i) {
	if (i < 0 || i >= _size) {
		throw std::out_of_range("index of out range");
	}
	
	for (int j = i; j < _size; ++j) {
		_arr[j] = _arr[j + 1];
		
	}
	_size--;

}

template <class T>
std::size_t Vector<T>::capacity() const {
	return _capacity;
}

template <class T>
void Vector<T>::print() const {
	if(_size == 0) {
		std::cout << "{} : _size = " << _size << ", _capacity = " << _capacity << std::endl;
	} else {
		std::cout << "{";
		for (size_t i = 0; i < _size - 1; ++i) {
			std::cout << _arr[i] << ", ";
		}
		std::cout << _arr[_size - 1] << "} : _size = " << _size << ", _capacity = " << _capacity << std::endl;
	}
}

template <class T>
void Vector<T>::increase_capacity(std::size_t new_capacity) {
	if (new_capacity <= _capacity) return;

	T * new_arr = new T[new_capacity];
	for (int i = 0; i < _capacity; ++i) {
		new_arr[i] = _arr[i];
	}

	_capacity = new_capacity;

	delete[] _arr;
	_arr = new_arr;
}

template <class T>
void Vector<T>::reset() {
	for (std::size_t i = 0; i != _size; ++i) {
		_arr[i] = T();
	}
}

// iterators
template <class T>
typename Vector<T>::iterator Vector<T>::begin() {
	return iterator(_arr);
}

template <class T>
typename Vector<T>::iterator Vector<T>::end() {
	return iterator(_arr + _size);
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

//const iterators
template <class T>
typename Vector<T>::const_iterator Vector<T>::begin() const {
	return const_iterator(_arr);
}

template <class T>
typename Vector<T>::const_iterator Vector<T>::end() const {
	return const_iterator(_arr + _size);
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