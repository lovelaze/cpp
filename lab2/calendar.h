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
	std::map<int, std::vector<std::string>> events_; // inten motsvarar en dag, i mjdn

public:

	Calendar();

	Calendar(const Calendar<T> &);
	template<class T2>
	Calendar(const Calendar<T2> &);

	Calendar<T> & operator=(const Calendar<T> &);
	template<class T2>
	Calendar<T> & operator=(const Calendar<T2> &);


	bool set_date(int year, int month, int day);

	bool add_event(std::string message);
	bool add_event(std::string message, int day);
	bool add_event(std::string message, int day, int month);
	bool add_event(std::string message, int day, int month, int year);

	bool remove_event(std::string message);
	bool remove_event(std::string message, int day);
	bool remove_event(std::string message, int day, int month);
	bool remove_event(std::string message, int day, int month, int year);

private:
	std::string & event_exists(T date, std::string message);
	std::string & event_exists(int day, int month, int year, std::string message);
};
}

#include "calendar.hxx"

#endif
