#ifndef MIDDLE_H
#define MIDDLE_H

#include "date.h"
#include <vector>
#include <string>

namespace lab2 {

class Middle : public Date {

protected:
	virtual bool is_leap_year() const = 0;
	bool is_valid_date() const;

	virtual void MJD_set_date(int) = 0;

public:

	// CONSTRUCTORS
	Middle();
	Middle(int mjdn);
	Middle(int year, int month, int day);

	virtual ~Middle();

	virtual Middle & operator=(const Date & date);
	

	// FUNCTIONS
	virtual int days_this_month() const;
	virtual std::string week_day_name() const;
	virtual std::string month_name() const;

	virtual Date & add_year(int n = 1);
	virtual Date & add_month(int n = 1);

	
	virtual int mod_julian_day() const = 0;



};

}

#endif