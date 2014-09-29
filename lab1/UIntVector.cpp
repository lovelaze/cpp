#include "UIntVector.h"

// constructors
UIntVector::UIntVector() : size_array(0), array(new unsigned int[size_array]) {

}

UIntVector::UIntVector(const std::size_t size) : size_array(size), array(new unsigned int[size_array]) {
	reset(); // set all elements to 0
}

UIntVector::UIntVector(const UIntVector & src) : size_array(src.size_array), array(new unsigned int[size_array]) {

	for (std::size_t i = 0; i != size_array; ++i) {
		array[i] = src.array[i];
	}
}

UIntVector::UIntVector(const std::initializer_list<unsigned int> args) : size_array(args.size()), array(new unsigned int[size_array]) {

	// fill the array with elements from the initializer list
	int i = 0;
	for (auto iter = args.begin(); iter != args.end(); ++iter) {
		array[i++] = *iter;
	}
}

UIntVector::UIntVector(UIntVector && other) : size_array(other.size_array), array(other.array) {
	other.size_array = 0;
	other.array = nullptr;

}

// destructor
UIntVector::~UIntVector() {
	delete [] array;
}

// operators

unsigned int & UIntVector::operator[] (const std::size_t index) {
	if (index < 0 || index >= size_array) {
		throw std::out_of_range("out of range");
	}

	return array[index];
}

const unsigned int & UIntVector::operator[] (const std::size_t index) const {
	if (index < 0 || index >= size_array) {
		throw std::out_of_range("out of range");
	}

	return array[index];
}

UIntVector & UIntVector::operator= (const UIntVector & src) {	
	if (&src != this) {

		unsigned int * new_array = new unsigned int[src.size_array];
		for (std::size_t i = 0; i != src.size_array; ++i) {
			new_array[i] = src.array[i];
		}

		delete [] array;
		
		size_array = src.size_array;
		array = new_array;

	}

	return *this;
}

UIntVector& UIntVector::operator= (UIntVector && other) {
	if (this != &other) {
		delete [] array;
		array = other.array;
		size_array = other.size_array;

		other.array = nullptr;
		other.size_array = 0;
	}

	return *this;
}



// methods
void UIntVector::reset() {
	for (std::size_t i = 0; i != size_array; ++i) {
		array[i] = 0;
	}
}

std::size_t UIntVector::size() const {
	return size_array;
}