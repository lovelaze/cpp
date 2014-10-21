#ifndef ISO_DATE_H
#define ISO_DATE_H

#include "Date.h"

namespace lab2 {

class IsoDate : public Date {
public:
	IsoDate();
	IsoDate(int day, int month, int year);

	int week_day() const;
	int days_this_month() const;

	std::string week_day_name() const;
	std::string month_name() const;

	int mod_julian_day() const = 0;

	virtual Date & add_year(int) = 0;

	virtual Date & add_month(int) = 0;
};

}


#endif 