#include <iostream>
#include <string>
#include <vector>
#include "Julian.h"


using namespace lab2;

std::vector<std::string> Julian::week_days = {"måndag", "tisdag", "onsdag", "torsdag", "fredag", "lördag"};

Julian::Julian(int day, int month, int year) : Date::Date(day, month, year, 7, 12) {
}

Julian::~Julian() {
	
}

// TODO
std::string Julian::week_day_name() const {
	return "";
}

// TODO
std::string Julian::month_name() const {
	return 0;
}

// FUNKISH?
int Julian::mod_julian_day() const {
	int a = (14-month_)/12;
	int y = year_ + 4800 - a;
	int m = month_ + (12*a) - 3;

	int jdn = day_ + (153*m + 2)/5 + (365*y) +(y/4) - (y/100) + (y/400) - 32045; // gregorian

	//int jdn = day_ + (((153*m) + 2)/5) + (365*y) + (y/4) - 32083; // julian

	int mjdn = jdn - 2400000.5;

	return mjdn;
}

// TODO
int Julian::days_this_month() const {
	return 0;
}
