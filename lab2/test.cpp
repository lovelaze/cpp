#include <iostream>
#include "julian.h"
#include "gregorian.h"
#include "kattistime.h"

using namespace lab2;
using namespace std;


int main() {

	time_t tp;
    time(&tp);    
    set_k_time(tp);


	Gregorian p(2016, 2, 28);
	cout << p.is_leap_year() << endl;

	++p;
	cout << p << endl;

	
	



}
