#include "gregorian.h"
#include "julian.h"
#include <iostream>
#include "kattistime.h"

using namespace lab2;
using namespace std;


int main() {



	time_t tp;
    time(&tp);    
    set_k_time(tp);

    
    Gregorian g = Julian(1858, 1, 1);
    cout << g << endl;
    cout << g.mod_julian_day() << endl << endl;

    for (int i = 1; i <= 13; ++i) {
    	Gregorian g(2000, i, 1);
    	//cout << g.month_name() << endl;
    }
    
    
   
	return 0;
}
