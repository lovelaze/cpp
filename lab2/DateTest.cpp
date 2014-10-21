#include <iostream>
#include "Julian.h"

int main() {

	lab2::Julian d(20, 10, 2014);
	d.debug();
	std::cout << d << std::endl;

	std::cout << ((d.mod_julian_day()) % 7) << std::endl;
	std::cout << d.week_day_name() << std::endl;


}