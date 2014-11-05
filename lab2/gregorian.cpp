#include "gregorian.h"
#include "kattistime.h"
#include <stdexcept>

using namespace lab2;

Gregorian::Gregorian() {
	time_t time;
	k_time(&time);

	struct tm * t = gmtime(&time);

	currYear_ = t->tm_year + 1900;
	currMonth_ = t->tm_mon + 1;  
    currDay_ = t->tm_mday;

    daysPerWeek_= 7;
    monthsPerYear_ = 12;
}

Gregorian::Gregorian(int mjdn) {
	daysPerWeek_= 7;
    monthsPerYear_ = 12;
	MJD_set_date(mjdn);
}

Gregorian::Gregorian(int year, int month, int day) : Middle(year, month, day) {
	if (!is_valid_date()) {
		throw std::out_of_range("invalid date");
	}

}

// TODO
Gregorian::Gregorian(const Date & date) : Middle(0,0,0) {
	MJD_set_date(date.mod_julian_day());
}

// TODO
Gregorian::Gregorian(const Date * datep) : Middle(0,0,0) {
	MJD_set_date(datep->mod_julian_day());
}

Gregorian & Gregorian::operator=(const Date & date) {
	if (this != &date) {
		daysPerWeek_ = date.days_per_week();
		monthsPerYear_ = date.months_per_year();
		MJD_set_date(date.mod_julian_day());
	}

	return *this;
}

// TODO
Gregorian Gregorian::operator++(int) {
	Gregorian g(this);
	++(*this);
	return g;
}

// TODO
Gregorian Gregorian::operator--(int) {
	Gregorian g(this);
	--(*this);
	return g;
}

// TODO
int Gregorian::mod_julian_day() const {
	int a = (14 - month()) / 12;
  	int y = year() + 4800 - a;
  	int m = month() + 12 * a - 3;

  	double jdn = day() + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;

	double mjdn = jdn - 2400000.5;

  	if(mjdn < 0) {
        mjdn--;
    }

  	return mjdn;
}

// TODO
bool Gregorian::is_leap_year() const {
	return (year() % 4 == 0) && (year() % 100 != 0 || year() % 400 == 0);
}

// TODO
void Gregorian::MJD_set_date(int mjd) {
	int jdn = mjd + 2400000.5 + 0.5;

  	int y = 4716, v = 3, j = 1401, u = 5, m = 2, s = 153, n = 12, w = 2, r = 4, B = 274277, p = 1461, C = -38;

  	int f = jdn + j + (((4 * jdn + B)/146097) * 3)/4 + C;
  	int e = r * f + v;
  	int g = (e % p)/r;
  	int h = u * g + w;

  	int day = (h % s)/u + 1;
  	int month = (((h/s) + m) % n) + 1;
  	int year = e/p - y + (n + m - month)/n;

  	currDay_ = day;
  	currMonth_ = month;
  	currYear_ = year;
}