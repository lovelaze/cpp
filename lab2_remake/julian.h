#ifndef JULIAN_H
#define JULIAN_H

#include "middle.h"

namespace lab2 {

class Julian : public Middle {

protected:
	virtual bool is_leap_year() const;

public:
	Julian();
	Julian(int year, int month, int day);
	Julian(const Date &);
	Julian(const Date *);

	Julian & operator=(const Date & date);

	using Date::operator++;
	using Date::operator--;
	Julian operator++(int);
	Julian operator--(int);

	int mod_julian_day() const;
	void MJD_set_date(int);


};

}

#endif