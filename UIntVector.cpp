#include "UIntVector.h"

UIntVector::UIntVector() {
	std::cout << "default constructor" << std::endl;

	_size = 0;
	_arr = new unsigned int[_size];
}

UIntVector::UIntVector(std::size_t size) {
	std::cout << "size init constructor" << std::endl;

	_size = size;
	_arr = new unsigned int[size];
	reset();
}

UIntVector::UIntVector(UIntVector const & src){
	std::cout << "copy and move constructor" << std::endl;

	_size = src._size;
	_arr = new unsigned int[_size];
	for (int i = 0; i < _size; ++i) {
		_arr[i] = src._arr[i];
	}

}

UIntVector::UIntVector(std::initializer_list<unsigned int> args) {
	std::cout << "initializer_list constructor" << std::endl;

	_size = args.size();
	_arr = new unsigned int[_size];

	int i = 0;
	for (auto iter = args.begin(); iter != args.end(); ++iter) {
		_arr[i++] = *iter;
	}

}

UIntVector::~UIntVector() {
	std::cout << "destructor" << std::endl;
	delete [] _arr;
}

UIntVector& UIntVector::operator= (const UIntVector & src) {
	std::cout << "assignment operator" << std::endl;

	if (&src != this) {
		_size = src._size;
		_arr = new unsigned int[_size];
		
		for (int i = 0; i < _size; i++) {
			_arr[i] = src._arr[i];
		}
	}

	return *this;
}

unsigned int& UIntVector::operator[] (const int index) {

	if (index < 0 || index >= _size) {
		throw std::out_of_range("out of range");
	}

	return _arr[index];
}

std::size_t UIntVector::size() const {
	return _size;
}

void UIntVector::reset() {
	for (int i = 0; i < _size; i++) {
		_arr[i] = 0;
	}
}
