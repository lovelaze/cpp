#ifndef JULIAN_H
#define JULIAN_H

#include "isodate.h"

namespace lab2 {

class Julian : public IsoDate {

public:
	Julian();
	Julian(int year, int month, int day);
	Julian(const Date &);
	Julian(const Date *);

	int mod_julian_day() const;

	using Date::operator++;
	using Date::operator--;
	Julian operator++(int);
	Julian operator--(int);

	void JD_set_date(int);

	bool is_leap_year() const;

};

}

#endif