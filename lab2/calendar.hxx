using namespace lab2;

#include <stdexcept>
#include <algorithm>

// CONSTRUCTORS

template<class T>
Calendar<T>::Calendar() {
	currentDate_ = T();
	
}

template<class T>
Calendar<T>::Calendar(const Calendar<T> & cal) {
	currentDate_ = cal.currentDate_;
	events_ = cal.events_;
}


template<class T>
template<class T2>
Calendar<T>::Calendar(const Calendar<T2> & cal) {
	currentDate_ = cal.currentDate_;
	events_ = cal.events_;
}

template<class T>
Calendar<T> & Calendar<T>::operator=(const Calendar<T> & cal) {
	currentDate_ = cal.currentDate_;
	events_ = cal.events_;
	return *this;
}

template<class T>
template<class T2>
Calendar<T> & Calendar<T>::operator=(const Calendar<T2> & cal) {

	currentDate_ = cal.currentDate_;
	events_ = cal.events_;
	return *this;
}


// FUNCTIONS


template<class T>
bool Calendar<T>::set_date(int year, int month, int day) {
	try {
		currentDate_ = T(year, month, day);
		return true;
	} catch (std::out_of_range & e) {
		return false;
	}
}

template<class T>
bool Calendar<T>::add_event(std::string message) {
	return add_event(message, currentDate_.day(), currentDate_.month(), currentDate_.year());
}

template<class T>
bool Calendar<T>::add_event(std::string message, int day) {
	return add_event(message, day, currentDate_.month(), currentDate_.year());
}

template<class T>
bool Calendar<T>::add_event(std::string message, int day, int month) {
	return add_event(message, day, month, currentDate_.year());
}

template<class T>
bool Calendar<T>::add_event(std::string message, int day, int month, int year) {
	try {
		T t(year, month, day);
		std::vector<std::string> & tmp = events_[t.mod_julian_day()];
		
		bool exists = (std::find(tmp.begin(), tmp.end(), message) != tmp.end());
		if (exists) return false;

		tmp.push_back(message); 
		return true;
		
	} catch (std::out_of_range & e) {
		return false;
	}
}

template<class T>
bool Calendar<T>::remove_event(std::string message) {
	return remove_event(message, currentDate_.day(), currentDate_.month(), currentDate_.year());
}


template<class T>
bool Calendar<T>::remove_event(std::string message, int day) {
	return remove_event(message, day, currentDate_.month(), currentDate_.year());
}

template<class T>
bool Calendar<T>::remove_event(std::string message, int day, int month) {
	return remove_event(message, day, month, currentDate_.year());
}

template<class T>
bool Calendar<T>::remove_event(std::string message, int day, int month, int year) {
	try {
		T t(year, month, day);
		std::vector<std::string> & tmp = events_[t.mod_julian_day()];

		auto ptr = std::find(tmp.begin(), tmp.end(), message);

		if (ptr != tmp.end()) { // event exists
			tmp.erase(ptr);
			return true;
		}


		return false;
		
	} catch (std::out_of_range & e) {
		return false;
	}
}


template<class T>
std::ostream & operator<<(std::ostream & os, const Calendar<T> & cal) {
	
	for (auto iter = cal.events_.lower_bound(cal.currentDate_.mod_julian_day()+1); iter != cal.events_.end(); ++iter) {
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2) {
			os << T(iter->first);
			os << " : ";
			os << (*iter2) << std::endl;
		}
	}

	return os;
}
