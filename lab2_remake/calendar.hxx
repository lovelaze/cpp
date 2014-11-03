using namespace lab2;

#include <stdexcept>
#include <algorithm>

// CONSTRUCTORS

template<class T>
Calendar<T>::Calendar() {
	currentDate_ = T();
	std::cout << "default" << std::endl;
	
}

template<class T>
Calendar<T>::Calendar(const Calendar<T> & cal) {
	std::cout << "copy1" << std::endl;
	currentDate_ = cal.currentDate_;
	// TODO ändra eventlistan
}


template<class T>
template<class T2>
Calendar<T>::Calendar(const Calendar<T2> & cal) {
	std::cout << "copy2" << std::endl;
	currentDate_ = cal.currentDate_;
	// TODO ändra eventlistan
}

template<class T>
Calendar<T> & Calendar<T>::operator=(const Calendar<T> & cal) {
	std::cout << "assignment1" << std::endl;
	currentDate_ = cal.currentDate_;
	// TODO ändra eventlistan
	return *this;
}

template<class T>
template<class T2>
Calendar<T> & Calendar<T>::operator=(const Calendar<T2> & cal) {
	std::cout << "assignment2" << std::endl;

	currentDate_ = cal.currentDate_;
	// TODO ändra eventlistan
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
bool Calendar<T>::add_event(std::string message, int year, int month, int day) {
	if (year == 0) {
		year = currentDate_.day();
	}
	if (month == 0) {
		month = currentDate_.month();
	}
	if (day == 0) {
		day = currentDate_.day();
	}
	
	try {
		T t(year, month, day);
		std::vector<std::string> & tmp = events_[t];
		bool exists = (std::find(tmp.begin(), tmp.end(), message) != tmp.end());

		if (exists) return false;
		
		tmp.push_back(message); 
		return true;
		
	} catch (std::out_of_range & e) {
		return false;
	}
}

template<class T>
bool Calendar<T>::event_exists(T t, std::string message) {
	std::vector<std::string> & tmp = events_[t];
	bool exists = (std::find(tmp.begin(), tmp.end(), message) != tmp.end());
	return exists;
}