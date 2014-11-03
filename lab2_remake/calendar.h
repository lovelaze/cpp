#ifndef CALENDAR_H
#define CALENDAR_H

#include "julian.h"
#include "gregorian.h"

namespace lab2 {

template<class T>
class Calendar {

public:
	 T currentDate_;

public:
	friend class Calendar<Julian>;
	friend class Calendar<Gregorian>;

	Calendar();


	Calendar(const Calendar<T> &);
	Calendar & operator=(const Calendar<T> &);


	bool set_date(int year, int month, int day);
	bool add_event(std::string event, int year=0, int month=0, int day=0);
	bool remove_event(std::string event, int year=0, int month=0, int day=0);

};
}

#include "calendar.hxx"

#endif