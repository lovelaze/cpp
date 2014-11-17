#ifndef DATE_H
#define DATE_H

#include <ostream>

namespace lab2 {

class Date {

protected:
	int currYear_;
	int currMonth_;
	int currDay_;

	int daysPerWeek_;
	int monthsPerYear_;

	virtual void MJD_set_date(int) = 0;
	

public:

	// CONSTRUCTORS
	Date();
	Date(int mjdn);
	Date(int year, int month, int day, int dpw, int mpy); 

	virtual ~Date();

	virtual Date & operator=(const Date & date);



	// FUNCTIONS
	int year() const;
	int month() const;
	int day() const;

	int days_per_week() const;
	int months_per_year() const;

	int week_day() const;

	virtual int days_this_month() const = 0;
	virtual std::string week_day_name() const = 0;
	virtual std::string month_name() const = 0;

	virtual Date & add_year(int n = 1) = 0;
	virtual Date & add_month(int n = 1) = 0;

	virtual int mod_julian_day() const = 0;


	// OPERATORS
	Date & operator++ ();
	Date & operator-- ();
	Date & operator+= (int);
	Date & operator-= (int);
	bool operator== (const Date &) const;
	bool operator!= (const Date &) const;
	bool operator< (const Date &) const;
	bool operator> (const Date &) const;
	bool operator<= (const Date &) const;
	bool operator>= (const Date &) const;
	int operator- (const Date &) const;

	void debug() const;

};

}

std::ostream & operator<<(std::ostream & os, const lab2::Date & date) ;



#endif