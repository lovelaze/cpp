#include <iostream>
#include "gregorian.h"
#include "julian.h"
#include "calendar.h"
#include "kattistime.h"
#include <cassert>

using namespace lab2;
using namespace std;

int main() {

	time_t tp;
    time(&tp);    
    set_k_time(tp);


    {
		Calendar<Gregorian> cg;
		Calendar<Julian> cj;

		Calendar<Gregorian> cgg(cg); // copy
		Calendar<Julian> cjj(cj);

		Calendar<Gregorian> cg2(cj);

		assert(cgg.currentDate_ == cg.currentDate_);
		assert(cjj.currentDate_ == cj.currentDate_);

		cgg = cj;
		cjj = cg;

		assert(cgg.currentDate_ == cg.currentDate_);
		assert(cjj.currentDate_ == cj.currentDate_);

		cg = cg;
		cg = cj;

		assert(cgg.currentDate_ == cg.currentDate_);
		assert(cjj.currentDate_ == cj.currentDate_);

		assert(cg.set_date(2016, 2, 29) == true);
		assert(cg.set_date(2015, 2, 29) == false);

		assert(cgg.add_event("hej", 2016, 2, 29) == true);
		assert(cgg.add_event("hej", 2016, 2, 29) == false);

		assert(cgg.add_event("hejsan", 2015, 2, 29) == false);	

	}

}