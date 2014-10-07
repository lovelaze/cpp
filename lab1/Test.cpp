#include "kth_cprog_template_container.hpp"

class A {

public:
	A() {

	}

	A(A && v) {

	}

	A & operator= (A && other);

};

int main() {

	Vector<A> v;

}