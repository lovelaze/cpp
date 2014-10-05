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
	p.print();


	cout << endl;
	p.print();

	
	Matrix x;

	std::cin >> x;
	x.print();


	return 0;
}