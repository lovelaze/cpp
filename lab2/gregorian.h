#ifndef GREGORIAN_H
#define GREGORIAN_H

#include "isodate.h"

namespace lab2 {

class Gregorian : public IsoDate {

public:
	Gregorian();
	Gregorian(int year, int month, int day);
	Gregorian(const Date &);
	Gregorian(const Date *);

	int mod_julian_day() const;

	Gregorian & operator++(int);
	Gregorian & operator--(int);
	Gregorian & operator++() {Date::operator++(); return *this;};
	Gregorian & operator--() {Date::operator--(); return *this;};

	void JD_set_date(int);

	bool is_leap_year() const;

};

}

#endif