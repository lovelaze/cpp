#ifndef GREGORIAN_H
#define GREGORIAN_H

#include "IsoDate.h"

namespace lab2 {

class Gregorian : public IsoDate {

public:
	Gregorian();
	Gregorian(int day, int month, int year);

	int mod_julian_day() const;

	Gregorian & operator++(int);
	Gregorian & operator--(int);

	Date & add_year(int n = 1);
	Date & add_month(int n = 1);

};

}

#endif