#ifndef DATE_H
#define DATE_H

#include <ostream>

namespace lab2 {

class Date {

protected:
	int year_;			// current year
	int month_;			// current month
	int day_;			// current day

	

	int daysPerWeek_;	// days per week
	int monthsPerYear_;	// months per year


public:
	Date();
	Date(int year, int month, int day, int daysPerWeek, int monthsPerYear);
	

	virtual ~Date();


	/** FUNCTIONS **/

	int year() const;
	int month() const;
	int day() const;

	int days_per_week() const;
	int months_per_year() const;

	virtual int week_day() const = 0;
	virtual int days_this_month() const = 0;

	void debug(); // debug function

	// pure virtual since this depends on what date is used
	virtual const std::string week_day_name() const = 0;
	// pure virtual since this depends on what date is used
	virtual const std::string month_name() const = 0;

	// modified julian day, pure virtual, depends on the date used
	virtual int mod_julian_day() const = 0;


	/** OPERATORS **/

	// prefix ++, add one day
	Date & operator++();

	// prefix --, remove one day
	Date & operator--();

	// +=, add days
	Date & operator+=(const int i);

	// -=, remove days
	Date & operator-=(const int i);

	// -, difference between dates
	int operator-(const Date & date) const;

	// Date comparisons
	bool operator==(const Date & date) const;
	bool operator!=(const Date & date) const;
	bool operator<(const Date & date) const;
	bool operator<=(const Date & date) const;
	bool operator>(const Date & date) const;
	bool operator>=(const Date & date) const;



	// add years
	virtual Date & add_year(const int n = 1) = 0;

	// add months
	virtual Date & add_month(const int n = 1) = 0;



};

}

std::ostream & operator<<(std::ostream & os, const lab2::Date & date);


#endif