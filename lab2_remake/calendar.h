#ifndef CALENDAR_H
#define CALENDAR_H

#include "julian.h"
#include "gregorian.h"
#include <vector>
#include <map>

namespace lab2 {


template<class T>
class Calendar {

public:
	T currentDate_;
	std::map<T, std::vector<std::string>> events_;
 	
 	bool event_exists(T t, std::string message);

public:
	//friend class Calendar<Julian>;
	//friend class Calendar<Gregorian>;

	Calendar();

	Calendar(const Calendar<T> &);
	template<class T2>
	Calendar(const Calendar<T2> &);

	Calendar<T> & operator=(const Calendar<T> &);
	template<class T2>
	Calendar<T> & operator=(const Calendar<T2> &);


	bool set_date(int year, int month, int day);
	bool add_event(std::string message, int year=0, int month=0, int day=0);
	bool remove_event(std::string message, int year=0, int month=0, int day=0);

};
}

#include "calendar.hxx"

#endif