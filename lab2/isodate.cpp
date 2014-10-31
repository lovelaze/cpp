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

	if (day < 1 || month < 1 || day > days_this_month() || month > 12) {
		throw std::out_of_range("illegal arguments");
	}
}


IsoDate::~IsoDate() {

}


Date & IsoDate::add_month(const int n) {

	if (n > 0) { // add months
		for (int i=0; i < n; ++i) {

			++month_;
			if (month_ > 12) {
				month_ = 1;
				add_year();
			}

			if (day_ > days_this_month()) {
				day_ = 1;
				operator+=(29);
			}

		}
	} else { // remove months
		for (int i=0; i > n; --i) {
			--month_;
			if (month_ < 1) {
				month_ = 12;
				add_year(-1);
			}

			if (day_ > days_this_month()) {
				day_ = 1;
				operator+=(29);
			}
		}
	}

	return *this;
}

Date & IsoDate::add_year(const int n) {

	year_ += n;
	if (month_ == 2 && day_ == 29 && !is_leap_year()) {
		day_ = 28;
	}
	return *this;
}


int IsoDate::week_day() const {
	return ((mod_julian_day()+2) % 7) + 1;
}

int IsoDate::days_this_month() const {
	if (month_ == 2 && is_leap_year()) return 29;
	return days_month[month_-1];
}

const std::string IsoDate::week_day_name() const {
	return IsoDate::days[week_day() - 1];
}

const std::string IsoDate::month_name() const {
	return IsoDate::months[month_ - 1];
}