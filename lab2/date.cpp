#include <iostream>
#include <string>
#include "date.h"

using namespace lab2;


/** CONSTRUCTORS **/
Date::Date() : year_(0), month_(0), day_(0), daysPerWeek_(0), monthsPerYear_(0) {
}

Date::Date(int year, int month, int day, int dpw, int mpy) : year_(year), month_(month), day_(day), daysPerWeek_(dpw), monthsPerYear_(mpy) {

}

Date::~Date() {

}


/** FUNCTIONS **/

int Date::year() const {
	return year_;

}

int Date::month() const {
	return month_;
}

int Date::day() const {
	return day_;
}


int Date::days_per_week() const {
	return daysPerWeek_;
}

int Date::months_per_year() const {
	return monthsPerYear_;
}


bool Date::operator==(const Date & date) const {
	return mod_julian_day() == date.mod_julian_day();
}

bool Date::operator!=(const Date & date) const {
	return mod_julian_day() != date.mod_julian_day();
}

bool Date::operator<(const Date & date) const {
	return mod_julian_day() < date.mod_julian_day();
}

bool Date::operator<=(const Date & date) const {
	return mod_julian_day() <= date.mod_julian_day();
}


bool Date::operator>(const Date & date) const {
	return mod_julian_day() > date.mod_julian_day();
}

bool Date::operator>=(const Date & date) const {
	return mod_julian_day() >= date.mod_julian_day();
}



// prefix ++, add one day
Date & Date::operator++() {

	if ((day_+1) >= days_this_month()) {
		if((month_+1) >= 12 ) {
			++year_;
			month_ = 1;
		} else {
			++month_;
		}

		day_ = 1;
	} else {
		++day_;
	}

	return *this;
}

// prefix --, remove one day
Date & Date::operator--() {
	--day_;
	return *this;
}

// +=, add days
Date & Date::operator+=(const int i) {
	day_ += i;
	return *this;
}

// -=, remove days
Date & Date::operator-=(const int i) {
	day_ -= i;
	return *this;
}

// -, difference between dates
int Date::operator-(const Date & date) const {

	return this->mod_julian_day() - date.mod_julian_day();
}




std::ostream & operator<<(std::ostream & os, const Date & date) {

	os << date.year() << "-";

	int m = date.month();
	if (m < 10) os << 0 << m;
		else os << m;

	os << "-";

	int d = date.day();
	if (d < 10) os << 0 << d;
		else os << d;
	return os;
}

void Date::debug() {
	std::cout << "day_ = " << day_ << std::endl;
	std::cout << "month_ = " << month_ << std::endl;
	std::cout << "year_ = " << year_ << std::endl;
	std::cout << "daysPerWeek_ = " << daysPerWeek_ << std::endl;
	std::cout << "monthsPerYear_ = " << monthsPerYear_ << std::endl;
	
}