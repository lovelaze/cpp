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

	Julian j(1913, 4, 8);

	cout << j << endl;
	Julian j2 = Gregorian(j);

	cout << j2 << endl;


	// dates.push_back(new D(*const_cast<const Date*>(dates[idx])));

}
