#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>
#include <stdexcept>
#include <iostream>
#include <vector>

template <class T> class Vector {
	
	public:
	// typedef T value_type;
	// typedef typename std::vector<T>::size_type size_type;
	typedef T* Iterator;
	typedef const T* Const_Iterator;

	//static_assert(std::is_move_constructible<T>::value, "type requires move constructable");
	//static_assert(std::is_move_assignable<T>::value, "type requires move assignable");

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
	std::size_t size() const;

	void push_back(T e);
	void insert(std::size_t i, T e);
	void clear();
	void erase(std::size_t i);
	std::size_t capacity() const;
	void print() const ;

	Iterator begin();

	Iterator end();

	Iterator find(const T &);

private:
	std::size_t _size; // size of the vector
	std::size_t _capacity; // number of elements the vector can hold
	T * _arr; // pointer to the first element of the vector

	//functions
	void increase_capacity(std::size_t new_capacity);
		

};

#include "Vector.hxx"

#endif