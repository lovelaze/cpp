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

		assert(cgg.add_event("hej", 29, 2, 2016) == true);
		assert(cgg.add_event("hej", 29, 2, 2016) == false);

		assert(cgg.add_event("hejsan", 29, 2, 2015) == false);

		assert(cgg.add_event("hejsan", 28, 2, 2015) == true);
		assert(cgg.add_event("hejsan", 28, 2, 2015) == false);
		assert(cgg.remove_event("hejsan", 28, 2, 2015) == true);
		assert(cgg.remove_event("hejsan", 28, 2, 2015) == false);
		assert(cgg.add_event("hejsan", 28, 2, 2015) == true);
		assert(cgg.remove_event("hejsan", 28, 2, 2015) == true);

		assert(cgg.add_event("pr0tt", 28, 2, 2018) == true);

		cout << cgg << endl;
	
	} 

	std::cout << "----------------------------------------" << std::endl;
	Calendar<Gregorian> cal;
	cal.set_date(2000, 12, 2);
	assert(cal.add_event("Basketträning", 4, 12, 2000) == true);
	assert(cal.add_event("Basketträning", 11, 12, 2000) == true);
	assert(cal.add_event("Nyårsfrukost", 1, 1, 2001) == true);
	assert(cal.add_event("Första advent", 1) == true); // år = 2000, månad = 12
	assert(cal.add_event("Vårdagjämning", 20, 3) == true); // år = 2000
	assert(cal.add_event("Julafton", 24, 12) == true);
	assert(cal.add_event("Kalle Anka hälsar god jul", 24) == true); // också på julafton
	assert(cal.add_event("Julafton", 24) == false); // En likadan händelse samma datum ska
	// ignoreras och inte sättas in i kalendern
	assert(cal.add_event("Min första cykel", 20, 12, 2000) == true);
	assert(cal.remove_event("Basketträning", 4) == true);
	std::cout << cal; // OBS! Vårdagjämning och första advent är
	// före nuvarande datum och skrivs inte ut
	std::cout << "----------------------------------------" << std::endl;
	assert(cal.remove_event("Vårdagjämning", 20, 3, 2000) == true);
	assert(cal.remove_event("Kalle Anka hälsar god jul", 24, 12, 2000) == true);
	assert(cal.set_date(2000, 11, 2) == true);
	if (! cal.remove_event("Julafton", 24)) {
	std::cout << " cal.remove_event(\"Julafton\", 24) tar inte"<< std::endl
	<< " bort något eftersom aktuell månad är november" << std::endl;
	}
	std::cout << "----------------------------------------" << std::endl;
	std::cout << cal;

}