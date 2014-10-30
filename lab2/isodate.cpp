#include "isodate.h"

#include <vector>
#include <string>
#include <stdexcept>

using namespace lab2;

std::vector<int> IsoDate::days_month = {31, 28, 31, 30, 31 , 30, 31, 31, 30, 31, 30, 31};
std::vector<std::string> IsoDate::days = {"monday", "tuesday", "wednessday", "thursday", "friday", "saturday", "sunday"};
std::vector<std::string> IsoDate::months = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};

IsoDate::IsoDate() : Date(0,0,0,7,12) {
	
}

IsoDate::IsoDate(int year, int month, int day) : Date(year, month, day, 7, 12) {

	if (day < 1 || month < 1 || day > IsoDate::days_month[month] || month > 12) {
		//throw std::out_of_range("illegal arguments");
	}
}

// TODO
int IsoDate::week_day() const {
	return ((mod_julian_day()+2) % 7) + 1;
}

// TODO
int IsoDate::days_this_month() const {
	return days_month[month_-1];
}

const std::string IsoDate::week_day_name() const {
	return IsoDate::days[week_day() - 1];
}

const std::string IsoDate::month_name() const {
	return IsoDate::months[month_];
}