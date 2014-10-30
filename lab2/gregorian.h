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

	Date & add_year(int n = 1);
	Date & add_month(int n = 1);

	void JD_set_date(int);

};

}

#endif