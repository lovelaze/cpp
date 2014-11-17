#include "julian.h"
#include "gregorian.h"
#include <stdexcept>

using namespace lab2;

Julian::Julian() {
	Gregorian g;

	int mjd = g.mod_julian_day();

	MJD_set_date(mjd);

	daysPerWeek_= 7;
    monthsPerYear_ = 12;

}

Julian::Julian(int mjdn) {
	daysPerWeek_= 7;
    monthsPerYear_ = 12;
	MJD_set_date(mjdn);
}

Julian::Julian(int year, int month, int day) : Middle(year, month, day) {
	if (!is_valid_date()) {
		throw std::out_of_range("invalid date");
	}
}

Julian::Julian(const Date & date) : Middle(0,0,0) {
	MJD_set_date(date.mod_julian_day());
}

Julian::Julian(const Date * datep) : Middle(0,0,0) {
	MJD_set_date(datep->mod_julian_day());
}


Julian & Julian::operator=(const Date & date) {
	if (this != &date) {
		daysPerWeek_ = date.days_per_week();
		monthsPerYear_ = date.months_per_year();
		MJD_set_date(date.mod_julian_day());
	}
	

	return *this;
}


bool Julian::is_leap_year() const {
	return !(year() % 4);
}




int Julian::mod_julian_day() const {
	int a = (14 - month()) / 12;
  	int y = year() + 4800 - a;
  	int m = month() + 12 * a - 3;

  	int jdn = day() + (153 * m + 2) / 5 + 365 * y + y / 4 -32083;

  	double mjdn = jdn - 2400000.5;

  	if(mjdn < 0) {
        mjdn--;
    }

  	return mjdn;
}
 

Julian Julian::operator++(int) {
	Julian g(this);
	++(*this);
	return g;
}

Julian Julian::operator--(int) {
    Julian g(this);
	--(*this);
	return g;
}

void Julian::MJD_set_date(int mjd) {

	int jdn = mjd + 2400000.5 + 0.5;

 	int b = 0;
 	int c = jdn + 32082;

 	int d = (4*c + 3)/1461;
 	int e = c - (int)(1461*d/4);
  	int m = (5*e + 2)/153;

 	int day = e - (int)((153*m + 2)/5) + 1;
  	int month = m + 3 - 12 * (int)(m/10);
  	int year = 100*b + d - 4800 + (int)(m/10);

 	currDay_ = day;
  	currMonth_ = month;
  	currYear_ = year;
}