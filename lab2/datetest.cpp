// projektlokala headerfiler
#include "kattistime.h"     
#include "julian.h"         
#include "gregorian.h"      

// STL headerfiler
#include <iostream>
#include <assert.h>             // assert(b) ger felmeddelande om b falsk
#include <ctime>


// Obs att testerna förutsätter att dina klasser returnerar
// månader och dagar indexerade från ETT. Testerna är inte
// fullständiga


using namespace std;

int main()
{
    using namespace lab2;        // Exponera funktionalitet i namnrymden lab2

    ////////////////////////////////////////////////////////////
    // Sätt tiden. OBS skicka inte nedanstående kod till kattis
    time_t mytime;
    time(&mytime);
    set_k_time(mytime);
    ////////////////////////////////////////////////////////////

    
    Julian tj;                  // ok: defaultkonstruktor ger dagens datum
    Gregorian gtoday;           // ok för gregorian också
    std::cout << "Idag är det " << gtoday << std::endl;
    assert(tj - gtoday == 0);
    Gregorian tg(2006, 10, 31); // ok: sätt datum explicit
                                // följande fungerar också:
                                // Gregorian(2000, Gregorian::October, 31)
    Date &j = tj;               // åtkomst av funktioner genom Dates interface
    Date &g = tg;       
    Date &today = gtoday;

    {
      Julian j1;
      Date & d1 = j1;
      Julian j2(d1);
      Date * dp = &j2;
      Julian j3(dp);
    }
     
    time_t tp;
    time(&tp);
    struct tm *t = gmtime(&tp);
    int year  = t->tm_year + 1900;
    int month = t->tm_mon + 1;      // månaderna och dagarna
    int day   = t->tm_mday;         // indexerade från ETT


    std::cout << "Testing constructors..." << std::endl;
    j.debug();
    assert(today.year() == year &&          // rätt initierad
           today.month() == month &&
           today.day() == day);
    assert(g.year() == 2006 &&              // rätt initierad
           g.month() == 10 &&
           g.day() == 31);                  // obs! ettindexerade


    std::cout << "Testing access..." << std::endl;
    assert(g.days_per_week() == 7);         // rätt antal dagar per vecka
    assert(j.days_per_week() == 7);         // rätt antal dagar per vecka
    assert(g.days_this_month() == 31);      // rätt antal dagar denna månad
    assert(g.months_per_year() == 12);      // rätt antal månader per år
    assert(j.months_per_year() == 12);      // rätt antal månader per år
    assert(g.week_day() == 2); // rätt veckodag

    std::cout << "Testing manipulation..." << std::endl;
    ++g;                                    // prefix ökning
    assert(g.week_day() == 3); // rätt veckodag
    --g;                                    // prefix minskning
    assert(g.week_day() == 2); // rätt veckodag
    g += 2;                                 // lägg till två dagar
    assert(g.week_day() == 4); // rätt veckodag
    g -= 3;                     // dra bort tre dagar
    g.add_month();              // lägg till en månad
    assert(g.month() == 11);
    g.add_month(-1);            // dra bort en månad    
    assert(g.month() == 10);
    g.add_year(10);             // lägg till tio år.
    assert(g.year() == 2016);
    
    std::cout << "Testing miscellaneous functions..." << std::endl;
    Julian jj(tj);              // kopieringskonstruktor
    const Gregorian gg;
    gg.year();                  // gg konstant, läsa går bra
    g = gg;                     // tilldelning
    assert(g.year() == gg.year());
    assert(g == gg);
    if(g == gg ||               // jämförelse
       g != gg ||               // jämförelse 
       g < gg ||                // jämförelse 
       g >= gg)                 // jämförelse 
        {}
    
    std::cout << "Testing boundary violations";
    Gregorian temp(1900, 1, 1);
    Date &d = temp;

    // loopa över dagar och kolla att inga gränser över/underskrids
    for(int i = 0; i < 100000; ++i, ++d)
        {
            if(!(i % 5000))        // utskrift på framsteg
                {
                    std::cout << ".";
                    flush(std::cout);
                }
            int m[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if(d.year() >= 1900 && 
               d.month() >= 1 && d.month() <= 12 &&
               d.day() >= 1 && d.day() <= m[d.month() - 1])
                {}
            else
                {
                    std::cout << std::endl;
                    std::cout << "boundary checks failed: " << std::endl;
                    std::cout << d.year() << ", "
                              << d.month() << ", "
                              << d.day() << std::endl;
                    return 1;
                }
        }
    std::cout << std::endl;

    std::cout << "Testing leap years..." << std::endl;
    // testa om skottåren för sekelskiften fungerar som de ska
    for(int y = 1958; y < 2500; y += 100)
        {
            Gregorian temp(y, 2, 28);
            Date &e = temp;
            ++e;                                   // lägg till en dag
            if((y % 400 == 0 && e.day() == 29) ||  // skottdag (obs! ETTindexerad)
               (y % 400 != 0 && e.day() == 1))     // ej skottdag
                {}
            else
                {
                    std::cout << std::endl << "leap day test failed: " << std::endl;
                    std::cout << e.year() << ", "
                              << e.month() << ", "
                              << e.day() << std::endl;
                    return 1;
                }
        }


    Gregorian ggg;
    Julian jjj;
    std::cout << "Today it is " << ggg << " gregorian and " << jjj << " julian";
    assert(ggg - jjj == 0);
    if (ggg - jjj == 0) std::cout << ". It is the same date" << std::endl;
    ggg = jjj;
    assert(ggg - jjj == 0);
    if (ggg - jjj == 0) std::cout << "It is still the same date" << std::endl;

    {

        Julian j(2000,11,19);

        Gregorian g(j);

        assert(g.year() == 2000);
        assert(g.month() == 12);
        assert(g.day() == 2);
        assert(g.days_per_week() == 7);
        assert(g.months_per_year() == 12);


    }

    {
        Gregorian date(1991, 11, 23);
        date.add_year();
        assert(date.year() == 1992);
        assert(date.month() == 11);
        assert(date.day() == 23);

        date.add_year(3);
        assert(date.year() == 1995);
        assert(date.month() == 11);
        assert(date.day() == 23);

        date.add_year(-1);
        assert(date.year() == 1994);
        assert(date.month() == 11);
        assert(date.day() == 23);

    }

    {
        Julian date(1991, 11, 23);
        date.add_year();
        assert(date.year() == 1992);
        assert(date.month() == 11);
        assert(date.day() == 23);

        date.add_year(3);
        assert(date.year() == 1995);
        assert(date.month() == 11);
        assert(date.day() == 23);

        date.add_year(-1);
        assert(date.year() == 1994);
        assert(date.month() == 11);
        assert(date.day() == 23);

    }

    {
        Gregorian date(1991, 11, 23);
        date.add_month();
        assert(date.year() == 1991);
        assert(date.month() == 12);
        assert(date.day() == 23);

        date.add_month(2);
        assert(date.year() == 1992);
        assert(date.month() == 2);
        assert(date.day() == 23);

        date.add_month(-1);
        assert(date.year() == 1992);
        assert(date.month() == 1);
        assert(date.day() == 23);

        date.add_month(-3);
        assert(date.year() == 1991);
        assert(date.month() == 10);
        assert(date.day() == 23);

        date = Gregorian(1991, 1, 31);

        date.add_month();

        assert(date.year() == 1991);
        assert(date.month() == 3);
        assert(date.day() == 2);

        date = Gregorian(1991, 3, 30);
        
        date.add_month(-1);
        assert(date.year() == 1991);
        assert(date.month() == 2);
        assert(date.day() == 28);


    }

    {
        Julian date(1991, 11, 23);
        date.add_month();
        assert(date.year() == 1991);
        assert(date.month() == 12);
        assert(date.day() == 23);

        date.add_month(2);
        assert(date.year() == 1992);
        assert(date.month() == 2);
        assert(date.day() == 23);

        date.add_month(-1);
        assert(date.year() == 1992);
        assert(date.month() == 1);
        assert(date.day() == 23);

        date.add_month(-3);
        assert(date.year() == 1991);
        assert(date.month() == 10);
        assert(date.day() == 23);

        date = Julian(1991, 1, 31);

        date.add_month();

        assert(date.year() == 1991);
        assert(date.month() == 3);
        assert(date.day() == 2);

        date = Julian(1991, 3, 30);
        
        date.add_month(-1);
        assert(date.year() == 1991);
        assert(date.month() == 2);
        assert(date.day() == 28);
    }

    {
        Gregorian date(1991, 11, 23);

        ++date;
        assert(date.year() == 1991);
        assert(date.month() == 11);
        assert(date.day() == 24);

        --date;
        assert(date.year() == 1991);
        assert(date.month() == 11);
        assert(date.day() == 23);

        date += 2;
        assert(date.year() == 1991);
        assert(date.month() == 11);
        assert(date.day() == 25);

        date += -1;
        assert(date.year() == 1991);
        assert(date.month() == 11);
        assert(date.day() == 24);

        date -= -1;
        assert(date.year() == 1991);
        assert(date.month() == 11);
        assert(date.day() == 25);

        date -= 1;
        assert(date.year() == 1991);
        assert(date.month() == 11);
        assert(date.day() == 24);

        date = Julian(1991, 11, 23);

        ++date;
        assert(date.year() == 1991);
        assert(date.month() == 12);
        assert(date.day() == 7);

        --date;
        assert(date.year() == 1991);
        assert(date.month() == 12);
        assert(date.day() == 6);

        date += 2;
        assert(date.year() == 1991);
        assert(date.month() == 12);
        assert(date.day() == 8);

        date += -1;
        assert(date.year() == 1991);
        assert(date.month() == 12);
        assert(date.day() == 7);

        date -= -1;
        assert(date.year() == 1991);
        assert(date.month() == 12);
        assert(date.day() == 8);

        date -= 1;
        assert(date.year() == 1991);
        assert(date.month() == 12);
        assert(date.day() == 7);

    }






    
    std::cout << std::endl << "All tests were successful." << std::endl;


    Julian j1(2319,01,7);
    cout << j1 << endl;
    Gregorian g1;
    g1 = j1;
    cout << g1 << endl;


    // följande ska inte gå att kompilera
#if 0
    gg.leap_year();             // fel: kan inte komma åt protected/private medlem
    gg = g;                     // fel: kan inte tilldela konstant
    ++gg;                       // fel: kan inte ändra på en konstant
#endif

    return 0;
}

