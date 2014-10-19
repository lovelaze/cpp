#ifndef DATE_H
#define DATE_H

#include <ostream>

namespace lab2 {
	class Date;
	std::ostream & operator<<(std::ostream & os, const Date &);

}

class lab2::Date {

private:
	int day_;			// current day
	int month_;			// current month
	int year_;			// current year

	int daysPerWeek_;	// days per week
	int monthsPerYear_;	// months per year


public:
	Date();
	Date(int day, int year, int month, int daysPerWeek, int monthsPerYear);

	virtual ~Date();


	/** FUNCTIONS **/

	int year() const;
	int month() const;
	int day() const;

	int week_day() const;
	int days_per_week() const;
	int days_this_month() const;
	int months_per_year() const;

	// pure virtual since this dependes on what date is used
	virtual std::string week_day_name() const = 0;
	// pure virtual since this dependes on what date is used
	virtual std::string month_name() const = 0;

	// add years
	Date & add_year(int n = 1);

	// add months
	Date & add_month(int n = 1);

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

	



};


#endif