#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>
#include <stdexcept>
#include <iostream>
//#include "VectorIterator.cpp"

#define private public

template <class T>
class Vector {
	
	private:
	std::size_t _size; // size of the vector
	std::size_t _capacity; // number of elements the vector can hold
	T * _arr; // pointer to the first element of the vector

	//functions
	void increase_capacity(std::size_t new_capacity);
	
	public:
	//typedef VectorIterator<T> iterator;
	//typedef VectorIterator<const T> const_iterator;

	typedef T* iterator;
	typedef const T* const_iterator;

	//static_assert(std::is_move_constructible<T>::value, "type requires move constructable");
	//static_assert(std::is_move_assignable<T>::value, "type requires move assignable");

	// constructors
	Vector();
	explicit Vector(std::size_t);
	Vector(const std::initializer_list<T>);
	Vector(std::size_t, T);
	Vector(const Vector<T> &); // TODO
	Vector(Vector<T> &&); // TODO

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

	/* // iterators
	iterator begin(); // TODO
	iterator end();	// TODO
	iterator find(const T &); // TODO
	const_iterator begin() const; // TODO
	const_iterator end() const; // TODO
	const_iterator find(const T &) const; // TODO */

	//const_iterator cbegin(); // TODO
	//const_iterator cend(); // TODO

};


#include "Vector.hxx"

#endif

