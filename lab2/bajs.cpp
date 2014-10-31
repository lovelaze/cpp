#include <iostream>


struct A {

	int a;

	A() {
		a = 1;
	}

	A & operator++() {
		a += 1;
		return *this;
	}

};

struct B : public A {

};

struct C : public B {

};



int main() {

	C a;
	++a;
	std::cout << a.a << std::endl;


}