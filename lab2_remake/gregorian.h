#ifndef GREGORIAN_H
#define GREGORIAN_H

#include "middle.h"

namespace lab2 {

class Gregorian : public Middle {

protected:
	virtual bool is_leap_year() const;

public:
	Gregorian();
	Gregorian(int year, int month, int day);
	Gregorian(const Date &);
	Gregorian(const Date *);

	Gregorian & operator=(const Date & date);

	using Date::operator++;
	using Date::operator--;
	Gregorian operator++(int);
	Gregorian operator--(int);

	int mod_julian_day() const;
	void MJD_set_date(int);

};

}

#endif