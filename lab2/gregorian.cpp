#include "gregorian.h"
#include "kattistime.h"

using namespace lab2;

Gregorian::Gregorian() {
	time_t time;
	k_time(&time);

	struct tm * t = gmtime(&time);

	this->year_ = t->tm_year + 1900;
	this->month_ = t->tm_mon + 1;  
    this->day_ = t->tm_mday;

    daysPerWeek_= 7;
    monthsPerYear_ = 12;

}

Gregorian::Gregorian(int day, int month, int year) : IsoDate(day, month, year) {

}


//TODO
/*int Gregorian::mod_julian_day() const {
	int a = (14-month_)/12;
	int y = year_ + 4800 - a;
	int m = month_ + (12*a) - 3;

	int jdn =  day_ + (((153*m) +2)/5) + (365*y) + (y/4) - (y/100) + (y/400) - 32045;

	return jdn;// - 2400000.5;

}*/

int Gregorian::mod_julian_day() const {
	int a = (14 - month()) / 12;
  	int y = year() + 4800 - a;
  	int m = month() + 12 * a - 3;

  	double jdn = day() + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;

	return jdn - 2400000.5;

}






//TODO
Gregorian & Gregorian::operator++(int) {
	return *this;
}

//TODO
Gregorian & Gregorian::operator--(int) {
	return *this;
}

//TODO
Date & Gregorian::add_year(int n) {
	return *this;
}

//TODO
Date & Gregorian::add_month(int n) {
	return *this;
}
