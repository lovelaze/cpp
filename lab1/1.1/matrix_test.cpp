#include "matrix.h"
#include "iostream"

using namespace std;

int main() {

	Matrix m(5,5);

	Matrix n(m);


	Matrix o = n;
	o = m;


	Matrix p (5);

	std::cout << p << std::endl;

	p = p*(-1);	
	std::cout << p << std::endl;

	p.transpose();
	std::cout << p << std::endl;





	Matrix x;

	cout << x << endl;
	std::cin >> x;
	std::cout << x << std::endl;

	cin.get();
	


	return 0;
} 
