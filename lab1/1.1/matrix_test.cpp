#include "matrix.h"
#include "iostream"

using namespace std;

int main() {

	Matrix m(5,5);

	Matrix n(m);


	Matrix o = n;
	o = m;


	Matrix p (2);

	std::cout << p << std::endl;

	p = p*(-1);	
	std::cout << p << std::endl;

	p.transpose();
	std::cout << p << std::endl;

	Matrix x;
	"[ 1 2 ; 3 4 ]" >> x;

	x = x*p;
	std::cout << x << std::endl;

	return 0;
} 
