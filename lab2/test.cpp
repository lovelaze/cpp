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

    Gregorian g(1995, 06, 19);
    cout << "g = " << g << endl;

    Gregorian g2 = ++g;
    g2 = g;
    cout << "g2 = " << g2 << endl;
 

    


    
	{
		Julian j(1995, 12, 19);
		j.add_month(-3);
		cout << "j = " << j << endl;
		j = Julian(j);
		cout << "j = " << j << endl;
		j = Gregorian(j);
		cout << "j = " << j << endl;

		Gregorian j2 = Julian(j);
		j2 = Julian(j);
		cout << "j2 = " << j2 << endl;
		j2 = Julian(j);
		cout << "j2 = " << j2 << endl;
	}

	{
		Gregorian g(1995, 12, 19);
		g.add_month(-3);
		cout << "g = " << g << endl;
		g = Julian(g);
		cout << "g = " << g << endl;
		g = Gregorian(g);
		cout << "g = " << g << endl;

		Julian g2 = Gregorian(g);
		g2 = Gregorian(g);
		cout << "g2 = " << g2 << endl;
		g2 = Julian(g);
		cout << "g2 = " << g2 << endl;
	}

	{
		Gregorian * p = new Gregorian(1995, 12, 19);
		cout << "*p = " << *p << endl;
		Julian g(p);
		cout << "g = " << g << endl;
		delete p;
	}


	
	return 0;
}
