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

	Julian j(2319,1,7);

	Gregorian g(j);

	Julian jj (j);

	jj = g;

	cout << j << endl;

	cout << g << endl;

	cout << jj << endl;

	
	



}
