#ifndef UINTVECTOR_H
#define UINTVECTOR_H

#include <iostream>
#include <cstddef>
#include <initializer_list>


class UIntVector {

private:
	unsigned int * _arr;
	std::size_t _size;

public:
	//constructors
	UIntVector();
	UIntVector(std::size_t);
	UIntVector(const UIntVector &);
	UIntVector(std::initializer_list<unsigned int>);

	//destructors
	~UIntVector();

	//operators
	UIntVector& operator= (const UIntVector &);
	unsigned int& operator[] (const int index);
	
	//functions
	std::size_t size() const;
	void reset();

};

#endif
