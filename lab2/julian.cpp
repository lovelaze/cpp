#include "julian.h"
#include "kattistime.h"
#include "gregorian.h"
#include <iostream>

using namespace lab2;

Julian::Julian() {
	Gregorian g;

	int mjd = g.mod_julian_day();

	JD_set_date(mjd);

}

Julian::Julian(int year, int month, int day) : IsoDate(year, month, day) {

}

Julian::Julian(const Date & date) {
	JD_set_date(date.mod_julian_day());
}

Julian::Julian(const Date * datep) {
	JD_set_date(datep->mod_julian_day());
}

bool Julian::is_leap_year() const {
	return !(year() % 4);
}




int Julian::mod_julian_day() const {
	int a = (14 - month()) / 12;
  	int y = year() + 4800 - a;
  	int m = month() + 12 * a - 3;

  	double jdn = day() + (153 * m + 2) / 5 + 365 * y + y / 4 -32083;
  	return jdn - 2400000.5;
}
 

//TODO
Julian & Julian::operator++(int) {
	return *this;
}

//TODO
Julian & Julian::operator--(int) {
	return *this;
}

void Julian::JD_set_date(int mjd) {

	int jdn = mjd + 2400000.5 + 0.5;

 	int b = 0;
 	int c = jdn + 32082;

 	int d = (4*c + 3)/1461;
 	int e = c - (int)(1461*d/4);
  	int m = (5*e + 2)/153;

 	int day = e - (int)((153*m + 2)/5) + 1;
  	int month = m + 3 - 12 * (int)(m/10);
  	int year = 100*b + d - 4800 + (int)(m/10);

 	day_ = day;
  	month_ = month;
  	year_ = year;
}