#ifndef JULIAN_H
#define JULIAN_H
#include "Date.h"

namespace lab2 {

	class Julian : public Date {

	public:
		Julian(int day, int month, int year);

		~Julian();
		
		std::string week_day_name() const;
		std::string month_name() const;
		int mod_julian_day() const;


	};

}

#endif