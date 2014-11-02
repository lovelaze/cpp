#include <iostream>
#include "gregorian.h"
#include "kattistime.h"

using namespace lab2;
using namespace std;


int main() {



	time_t tp;
    time(&tp);    
    set_k_time(tp);

    Gregorian g(1995, 06, 19);

	
	return 0;
}
