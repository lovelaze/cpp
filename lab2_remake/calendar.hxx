using namespace lab2;

template<class T>
Calendar<T>::Calendar() {
	currentDate_ = T();
	
}

template<class T>
Calendar<T>::Calendar(const Calendar<T> & cal) {
	currentDate_ = cal.currentDate_;
	// TODO ändra eventlistan
	
}

template<Class T>
Calendar<T> & Calendar<T>::Calendar(const Calendar<T> & cal) {
	currentDate_ = cal.currentDate_;
	// TODO ändra eventlistan
}