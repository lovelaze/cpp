#include <iostream>
#include <string>
#include <cstdlib>
#include "hello.h"

int main (int argc, char * argv[]) {

	if (argc == 1) {
		printHello("Hello, world!\n");
	} else if ( argc == 2) {

		std::string s = argv[1];
		printHello("Hello, " + s + "!\n");
	} else if ( argc == 3) {
		int a =  std::atoi(argv[2]);
		if ( a > 0) {
			printHello("Hello, ");
			for (int i = 0; i < a - 1; i++) {
				printHello(std::string(argv[1]) + " ");
			}
			printHello(std::string(argv[1]) + "!\n");
		} else {
			std::cerr << "error: 2nd argument must be an integral greater than zero!" << std::endl;
		}
	} else if ( argc > 3) {
		std::cerr << "error: Too many arguments" << std::endl;
	}

	return 0;
}
