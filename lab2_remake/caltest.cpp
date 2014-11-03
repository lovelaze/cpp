#include <iostream>
#include "gregorian.h"
#include "julian.h"
#include "calendar.h"
#include "kattistime.h"

using namespace lab2;
using namespace std;

int main() {

	time_t tp;
    time(&tp);    
    set_k_time(tp);

	Calendar<Gregorian> cg;
	Calendar<Julian> cj;

	cout << cg.currentDate_ << endl;
	cout << cj.currentDate_ << endl;

	Calendar<Gregorian> cgg = cg;
	//Calendar<Gregorian> cgj(cj);
	cout << cgg.currentDate_ << endl;
	//cout << cgj.currentDate_ << endl;
}