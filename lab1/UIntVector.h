#ifndef UINTVECTOR_H
#define UINTVECTOR_H

#include <iostream>
#include <cstddef>
#include <initializer_list>
#include <stdexcept>


class UIntVector {

private:
	std::size_t size_array;
	unsigned int * array;

public:
	// constructors
	UIntVector();
	explicit UIntVector(const std::size_t);
	UIntVector(const UIntVector &);
	UIntVector(const std::initializer_list<unsigned int>);
	UIntVector(UIntVector && other);

	// destructor
	~UIntVector();

	// operators
	unsigned int & operator[] (const std::size_t);
	const unsigned int & operator[] (const std::size_t) const;
	UIntVector & operator= (const UIntVector &);
	UIntVector& operator= (UIntVector && other);

	// methods
	void reset();
	std::size_t size() const;


};

#endif