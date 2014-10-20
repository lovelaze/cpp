#include <iostream>
#include <string>
#include "Date.h"

using namespace lab2;


/** CONSTRUCTORS **/
Date::Date() : day_(0), month_(0), year_(0), daysPerWeek_(0), monthsPerYear_(0) {

}

Date::Date(int day, int month, int year, int dpw, int mpy) : day_(day), month_(month), year_(year), daysPerWeek_(dpw), monthsPerYear_(mpy) {

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

int Date::week_day() const {
	return 0; // TODO
}

int Date::days_per_week() const {
	return daysPerWeek_;
}

int Date::days_this_month() const {
	return 0; // TODO
}

int Date::months_per_year() const {
	return monthsPerYear_;
}


std::ostream & operator<<(std::ostream & os, const Date &) {

	return os;
}

void Date::debug() {
	std::cout << "day_ = " << day_ << std::endl;
	std::cout << "month_ = " << month_ << std::endl;
	std::cout << "year_ = " << year_ << std::endl;
	std::cout << "daysPerWeek_ = " << daysPerWeek_ << std::endl;
	std::cout << "monthsPerYear_ = " << monthsPerYear_ << std::endl;
	
}