#ifndef UINTVECTOR_H
#define UINTVECTOR_H

#include <iostream>
#include <cstddef>
#include <initializer_list>
#include <stdexcept>


class UIntVector {

private:
	std::size_t _size;
	unsigned int * _arr;
	

public:
	//constructors
	UIntVector();
	UIntVector(std::size_t);
	UIntVector(const UIntVector &);
	UIntVector(std::initializer_list<unsigned int>);

	//destructors
	~UIntVector();

	//operators
	UIntVector& operator= (const UIntVector&);
	
	unsigned int& operator[] (const std::size_t);
	const unsigned int& operator[](const std::size_t) const;

	//functions
	std::size_t size() const;
	void reset();

};

#endif
