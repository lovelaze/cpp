#include <iostream>
#include "Vector.h"

using namespace std;

int main(int argc, char const *argv[])
{

	Vector<unsigned int> v {1,2,3,4,5,6};
	v.print();
	cout << "size = " << v.size() << endl;

	v.push_back(0);
	v.print();
	cout << "size = " << v.size() << endl;

	v.insert(3, 1337);
	v.print();
	cout << "size = " << v.size() << endl;

	v.erase(3);
	v.print();
	cout << "size = " << v.size() << endl;

	v.clear();
	v.print();
	cout << "size = " << v.size() << endl;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.print();
	cout << "size = " << v.size() << endl;



	for (auto it = v.begin(); it != v.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	cout << v[2] << endl;

	//Vector<unsigned int> v2(v);

	return 0;
}