//#include "Vector.h"             // inkludera din headerfil h�r
#include "kth_cprog_template_container.hpp"
#include <assert.h>             // assert(b) ger felmeddelande om b falsk


int main()
{
    Vector<double> v;           // ok: defaultkonstruktor ger vektor med flyttal
    Vector<char> *a = new Vector<char>[2];  // dynamiskt allokerade ser ut s� h�r
    delete [] a;

    v.print();

    assert(v.size() == 0);      // tom fr�n b�rjan
    v.push_back(3.14);          // l�gg till ett element sist 
    assert(v.size() == 1);      // nu ligger ett element i vektorn
    v.insert(0, 2.10);          // l�gg till f�re element 0, dvs f�rst
    assert(v[0] == 2.10 &&      // hamnade de r�tt?
	   v[1] == 3.14);       
    assert(v.size() == 2);      // nu ligger tv� element i vektorn
    
    //v.sort(false);              // sortera i fallande ordning
    double temp = v[0];
    v[0] = v[1];
    v[1] = temp;

    v.print();

    assert(v[0] == 3.14 &&      // hamnade de r�tt?
	   v[1] == 2.10);       
    assert(v.size() == 2);      // ingenting �ndrat?
    v[1] = 2.11;                // tilldelning av enstaka element;

    const Vector<double> &vc = v;  // skapa konstant referens
    assert(vc.size() == 2);     // ok: �ndrar ej vektorn som �r konstant
    assert(vc[0] == 3.14 &&     // ok: �ndrar ej vektorn som �r konstant
	   vc[1] == 2.11);
    
    v.erase(0);                 // ta bort f�rsta elementet               
    assert(v.size() == 1);      // r�tt antal elelment
    v.clear();                  // t�m hela vektorn
    assert(v.size() == 0);      // tom n�r alla element �r borttagna
    
    v.print();

    Vector<double> v2 = v;
    assert(v.size() == 0);
    assert(v2.size() == 0);


    Vector<double> v3;
    
    v3 = v2;

    
    // TEST ITERATORS

    Vector<double> v4 {1,2,34,5,6,7};
    v4.print();

    for (auto iter = v4.begin(); iter != v4.end(); ++iter) {
        std::cout << *iter << ", ";
    }
    std::cout << std::endl;

    auto d = v4.find(34);

    std::cout << *d << std::endl;
    *d = 17;
    v4.print();

    const Vector<double> v5 {1,3,5,62,4,1,17,92,13};
    for (auto iter = v5.begin(); iter != v5.end(); ++iter) {
        std::cout << *iter << ", ";
    }

    std::cout << std::endl << std::endl;
    v5.print();
    auto f = v5.find(5);
    std::cout << "*f = " << *f << std::endl;

    auto g  = v5.find(4);
    std::cout <<  "*g = " << *g << std::endl;
    g -= 1;
    std::cout <<  "*g = " << *g << std::endl;
    std::cout << "(g > f) = " << (g > f) << std::endl;
    std::cout << "(g == f) = " << (g == f) << std::endl;
    std::cout << "(g < f) = " << (g < f) << std::endl;

    v5.print();
    std::cout << "test1" << std::endl;

    std::cout << "(g-f) = " << (g-f) << std::endl;
    std::cout << "v5[g-f] = " << v5[g-f] << std::endl;
    std::cout << "test2" << std::endl;

    //


    std::size_t i = 2;
    v5.print();
    v5.erase(i);
    v5.print();

    // *f = 3; //fel : tilldelning till const

    // kontrollera att f�ljande rader inte g�r att kompilera
   // vc[0] = 3.1415;             // fel: tilldelning av konstant objekt
   // Vector<char> c = v;         // fel: tilldelning av olika typer

    return 0;
}
