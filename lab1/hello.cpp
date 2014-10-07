#include "hello.h"
#include <iostream>
#include <string>

void printHello(int argc, char * argv[]) {
	if (argc == 1) {
		std::cout << "Hello, world!" << std::endl;
	} else if ( argc == 2) {

		std::string s = argv[1];
		std::cout << "Hello, " << s << "!" << std::endl;
	} else if ( argc == 3) {
		int a =  std::atoi(argv[2]);
		if ( a > 0) {
			std::cout << "Hello, ";
			for (int i = 0; i < a - 1; ++i) {
				std::cout << argv[1] << " ";
			}
			std::cout << argv[1] << "!" << std::endl;
		} else {
			std::cerr << "error: 2nd argument must be an integral greater than zero!" << std::endl;
		}
	} else if ( argc > 3) {
		std::cerr << "error: Too many arguments" << std::endl;
	}
}

