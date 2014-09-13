#include <iostream>
#include "Vector.h"

using namespace std;

int main(int argc, char const *argv[])
{

	Vector<unsigned int> v {1,2,3,4,5,6};
	v.print();
	std::cout << "size = " << v.size() << endl;

	v.push_back(0);
	v.print();
	std::cout << "size = " << v.size() << endl;

	v.insert(3, 1337);
	v.print();
	std::cout << "size = " << v.size() << endl;

	v.erase(3);
	v.print();
	std::cout << "size = " << v.size() << endl;

	v.clear();
	v.print();
	std::cout << "size = " << v.size() << endl;

	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.print();
	std::cout << "size = " << v.size() << endl;
	std::cout << "capacity = " << v.capacity() << endl;


	
	return 0;
}