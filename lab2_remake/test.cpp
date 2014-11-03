#include "gregorian.h"
#include "julian.h"
#include <iostream>
#include "kattistime.h"
#include <cassert>

using namespace lab2;
using namespace std;


int main() {



	time_t tp;
    time(&tp);    
    set_k_time(tp);

    for (int i = 1000; i < 2500; ++i) {
    	for (int j = 1; j< 28; ++j) {
    		Gregorian g = Gregorian(i, 1, j);
    		assert(g.week_day() >= 0);
    		assert(g.week_day_name().length() > 0);
    		assert(g.month_name().length() > 0);
    	}

    }
    
    

    
   
	return 0;
}
