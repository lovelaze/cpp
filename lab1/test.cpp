#include <iostream>
#include <string>

class Test {

private:
	int a;
public:
	Test();
	Test(int a);

	void printA() {
		std::cout << a << std::endl;
	};
};


int main() {

	Test t;

	t.printA();


}