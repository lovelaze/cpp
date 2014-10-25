#ifndef JULIAN_H
#define JULIAN_H

#include "IsoDate.h"

namespace lab2 {

class Julian : public IsoDate {

public:
	Julian();
	Julian(int day, int month, int year);

	int mod_julian_day() const;

	Julian & operator++(int);
	Julian & operator--(int);

	Date & add_year(int n = 1);
	Date & add_month(int n = 1);

};

}

#endif