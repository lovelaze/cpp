#include "matrix.h"
#include "iostream"

using namespace std;


int main() {

	Matrix m(5,5);
	cerr << "rows = " << m.rows() << endl;
	cerr << "cols = " << m.cols() << endl;

	Matrix n(m);

	cerr << "rows = " << n.rows() << endl;
	cerr << "cols = " << n.cols() << endl;

	Matrix o = n;
	o = m;

	Matrix p (5);
	std::cout << p << std::endl;


	cout << endl;
	std::cout << p << std::endl;

	
	Matrix x;

	std::cin >> x;
	std::cout << x << std::endl;

	cin.get();
	


	return 0;
} 