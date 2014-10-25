#include <iostream>
#include "Julian.h"
#include "Gregorian.h"

int main() {

	lab2::Gregorian d(1, 5, 2001);
	lab2::Gregorian e(1, 5, 2001);
	lab2::Julian f(5, 5, 2001);

	d.debug();
	std::cout << d << std::endl;

	std::cout << ((d.mod_julian_day()) % 7) << std::endl;
	std::cout << d.week_day_name() << std::endl;
	std::cout << d.days_this_month() << std::endl;


	std::cout << (d == e) << std::endl;
	std::cout << (d > e) << std::endl;
	std::cout << (d < e) << std::endl;


	std::cout << d.mod_julian_day() << std::endl;
	std::cout << f.mod_julian_day() << std::endl;
}
