#include "IsoDate.h"

#include <vector>
#include <string>

using namespace lab2;

IsoDate::IsoDate() : Date() {

}

IsoDate::IsoDate(int day, int month, int year) : Date(day, month, year, 7, 12) {

}

// TODO
int IsoDate::week_day() const {
	return 0;
}

// TODO
int IsoDate::days_this_month() const {
	return 0;
}

// TODO
std::string IsoDate::week_day_name() const {
	static std::vector<std::string> days = {"monday", "tuesday", "wednessday", "thursday", "friday", "saturday", "sunday"};
	return days[week_day()];
}

// TODO
std::string IsoDate::month_name() const {
	static std::vector<std::string> months = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
	return months[month_];
}
