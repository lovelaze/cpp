#include <iostream>
#include <string>
#include <type_traits>


int main() {

	std::cout << std::is_move_assignable<int>::value << std::cout;

	return 0;
}