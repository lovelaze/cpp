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

	Julian & operator++(int);
	Julian & operator--(int);

	Date & add_year(int n = 1);
	Date & add_month(int n = 1);

	void JD_set_date(int);

};

}

#endif