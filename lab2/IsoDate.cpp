#include "IsoDate.h"

#include <vector>
#include <string>

using namespace lab2;

std::vector<int> IsoDate::days_month = {31, 28, 31, 30, 31 , 30, 31, 31, 30, 31, 30, 31};
std::vector<std::string> IsoDate::days = {"monday", "tuesday", "wednessday", "thursday", "friday", "saturday", "sunday"};
std::vector<std::string> IsoDate::months = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};

IsoDate::IsoDate() : Date() {

}

IsoDate::IsoDate(int day, int month, int year) : Date(day, month, year, 7, 12) {

}

// TODO
int IsoDate::week_day() const {
	return (mod_julian_day() % 7) + 1;
}

// TODO
int IsoDate::days_this_month() const {
	return days_month[month_];
}

const std::string IsoDate::week_day_name() const {
	return IsoDate::days[week_day() - 1];
}

const std::string IsoDate::month_name() const {
	return IsoDate::months[month_];
}
