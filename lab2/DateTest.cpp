#include <iostream>
#include "julian.h"
#include "gregorian.h"
#include "kattistime.h"

int main() {

	time_t tp;
    time(&tp);    
    set_k_time(tp);


	lab2::Gregorian g;
	lab2::Julian j;

	std::cout << g << std::endl;
	g.debug();
	std::cout << g.mod_julian_day() << std::endl;
	std::cout << g.week_day() << std::endl;
	std::cout << g.week_day_name() << std::endl;
	
	std::cout << std::endl;

	std::cout << j << std::endl;
	j.debug();
	std::cout << j.mod_julian_day() << std::endl;

	

}
