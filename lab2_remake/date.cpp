#include "date.h"
#include <iostream>

using namespace lab2;

Date::Date() : currYear_(0), currMonth_(0), currDay_(0), daysPerWeek_(0), monthsPerYear_(0) {

}

Date::Date(int year, int month, int day, int dpw, int mpy) : currYear_(year), currMonth_(month), currDay_(day), daysPerWeek_(dpw), monthsPerYear_(mpy) {

}

/*
Date::Date(const Date * date) : daysPerWeek_(date->days_per_week()), monthsPerYear_(date->months_per_year()) {
	//MJD_set_date(date->mod_julian_day());
}

Date::Date(const Date & date) : daysPerWeek_(date.days_per_week(), monthsPerYear_(date.months_per_year()) {
	//MJD_set_date(date.mod_julian_day());
}*/

Date::~Date() {

}

int Date::year() const {
	return currYear_;
}

int Date::month() const {
	return currMonth_;
}

int Date::day() const {
	return currDay_;
}

int Date::days_per_week() const {
	return daysPerWeek_;
}

int Date::months_per_year() const {
	return monthsPerYear_;
}

int Date::week_day() const {
	return ((mod_julian_day()+2) % days_per_week()) + 1;
}


// TODO
Date & Date::operator++ () {
	(*this)+=1;
	return *this;
}

// TODO
Date & Date::operator-- () {
	(*this)-=1;
	return *this;
}

// TODO
Date & Date::operator+= (int i) {

	if (i < 0 ) {
		Date::operator-=(-i);
	} else {
		for (int day=i; day > 0; --day) {

			++currDay_;

			if (currDay_ > days_this_month()) {
				currDay_ = 1;
				add_month();
			}
		}
	}

	return *this;
}

// TODO
Date & Date::operator-= (int i) {

	if( i < 0) {
		Date::operator+=(-i);
	} else {
		for (int day=i; day > 0; --day) {

			--currDay_;

		    if (currDay_ < 1) {
 			    add_month(-1);
		    	currDay_ = days_this_month();
		    }

		}
	}

	return *this;
}

bool Date::operator== (const Date & date) const {
	return mod_julian_day() == date.mod_julian_day();
}

bool Date::operator!= (const Date & date) const {
	return mod_julian_day() != date.mod_julian_day();
}

bool Date::operator< (const Date & date) const {
	return mod_julian_day() < date.mod_julian_day();
}

bool Date::operator> (const Date & date) const {
	return mod_julian_day() > date.mod_julian_day();
}

bool Date::operator<= (const Date & date) const {
	return mod_julian_day() <= date.mod_julian_day();
}

bool Date::operator>= (const Date & date) const {
	return mod_julian_day() >= date.mod_julian_day();
}

int Date::operator- (const Date & date) const {
	return mod_julian_day() - date.mod_julian_day();
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
	std::cout << "day = " << currDay_ << std::endl;
	std::cout << "month = " << currMonth_ << std::endl;
	std::cout << "year = " << currYear_ << std::endl;
	std::cout << "dpw = " << daysPerWeek_ << std::endl;
	std::cout << "mpy = " << monthsPerYear_ << std::endl;
}