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

    
    Gregorian g = Gregorian(1857, 1, 1);
    cout << g.week_day() << endl;

    
   
	return 0;
}
