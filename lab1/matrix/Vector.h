#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>
#include <stdexcept>
#include <iostream>
#include <type_traits>

#define private public
using namespace std;

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


#include "Vector.hxx"

#endif

