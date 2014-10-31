#ifndef ISO_DATE_H
#define ISO_DATE_H

#include "date.h"
#include <vector>
#include <string>

namespace lab2 {

class IsoDate : public Date {
public:
	IsoDate();
	IsoDate(int year, int month, int day);
	
	virtual ~IsoDate();

	int week_day() const;
	
	int days_this_month() const;

	const std::string week_day_name() const;
	const std::string month_name() const;

	int mod_julian_day() const = 0;

	virtual Date & add_year(const int n = 1);

	virtual Date & add_month(const int n = 1);

	virtual void JD_set_date(int) = 0;

	virtual bool is_leap_year() const = 0;





private:
	static std::vector<int> days_month;
	static std::vector<std::string> days; 
	static std::vector<std::string> months;;
};

}


#endif 