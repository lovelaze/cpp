#include "Julian.h"


using namespace lab2;

Julian::Julian() : IsoDate() {

}

Julian::Julian(int day, int month, int year) : IsoDate(day, month, year) {

}

//TODO
int Julian::mod_julian_day() const {
	return 0;
}

//TODO
Date & Julian::add_year(int n) {
	return *this;
}

//TODO
Date & Julian::add_month(int n) {
	return *this;
}