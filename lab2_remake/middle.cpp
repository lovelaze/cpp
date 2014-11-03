#include "middle.h"
#include <string>
#include <vector>
#include <stdexcept>

using namespace lab2;

//std::vector<int> Middle::days_month = {31, 28, 31, 30, 31 , 30, 31, 31, 30, 31, 30, 31};
//std::vector<std::string> Middle::days = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
//std::vector<std::string> Middle::months = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};


Middle::Middle() : Date() {

}

Middle::Middle(int year, int month, int day) : Date(year, month, day, 7, 12) {

}

int Middle::days_this_month() const {
	
	if(month() == 1 || month() == 3 || month() == 5 || month() == 7 || month() == 8 || month() == 10 || month() == 12) {
		return 31;
	} else if(month() == 4 || month() == 6 || month() == 9 || month() == 11) {
		return 30;
	} else if(month() == 2) {
		if(is_leap_year()) {
	  		return 29;
		}

		return 28;
	}

  throw std::out_of_range("Illegal month");

}

std::string Middle::week_day_name() const {
	
	if(week_day() == 1) {
    	return std::string("monday");
	} else if(week_day() == 2) {
	    return std::string("tuesday");
	} else if(week_day() == 3) {
	    return std::string("wednesday");
	} else if(week_day() == 4) {
	    return std::string("thursday");
	} else if(week_day() == 5) {
	    return std::string("friday");
	} else if(week_day() == 6) {
    	return std::string("saturday");
	} else if(week_day() == 7) {
	    return std::string("sunday");
	} 

	throw std::out_of_range("week_day_name out of range");


}

std::string Middle::month_name() const {
	
	if(month() == 1) {
		return std::string("january");
	} else if(month() == 2) {
		return std::string("february");
	} else if(month() == 3) {
		return std::string("march");
	} else if(month() == 4) {
		return std::string("april");
	} else if(month() == 5) {
		return std::string("may");
	} else if(month() == 6) {
		return std::string("june");
	} else if(month() == 7) {
		return std::string("july");
	} else if(month() == 8) {
		return std::string("august");
	} else if(month() == 9) {
		return std::string("september");
	} else if(month() == 10) {
	    return std::string("october");
	} else if(month() == 11) {
	    return std::string("november");
	} else if(month() == 12) {
	    return std::string("december");
	}

	throw std::out_of_range("month_name out of range");



}


// TODO
Date & Middle::add_year(int n) {

	if (n > 0) {
		currYear_ += n;
		if (currMonth_ == 2 && currDay_ == 29 && !is_leap_year()) {
			currDay_ = 28;
		}
	} else if (n < 0) {
		currYear_ -= -n;
		if (currMonth_ == 2 && currDay_ == 29 && !is_leap_year()) {
			currDay_ = 28;
		}
	}
	
	return *this;
}

// TODO
Date & Middle::add_month(int n) {

	if (n > 0) { // add months
		for (int i=0; i < n; ++i) {

			++currMonth_;
			if (currMonth_ > 12) {
				currMonth_ = 1;
				add_year();
			}

			if (currDay_ > days_this_month()) {
				add_month(-1);
				operator+=(30);
			}

		}
	} else { // remove months
		for (int i=0; i > n; --i) {
			--currMonth_;
			if (currMonth_ < 1) {
				currMonth_ = 12;
				add_year(-1);
			}

			if (currDay_ > days_this_month()) {
				add_month();
				operator-=(30);
			}
		}
	}

	return *this;
}

bool Middle::is_valid_date() const {

	if (day() < 1 || day() > days_this_month()) return false;
	if (month() < 1 || month() > 12) return false;
	return true;

	//return !(day < 1 || day > days_this_month() || month < 1 || month > 12);

}