#include <iostream>
#include <stdexcept>
#include "kth_cprog_simple_container.hpp"

using namespace std;

void printVector(UIntVector & v) {
    std::cout << "[";
    std::size_t i = 0;
    for (i = 0; i < v.size() - 1; ++i) {
        std::cout << v[i] << ", ";
    }
    std::cout << v[i] << "]" << std::endl;
}




int main()
{
    
    //Några saker som ska fungera:
    UIntVector a(7);           // initiering med 7 element
    UIntVector b(a);           // kopieringskonstruktor 
    UIntVector c = a;          // kopieringskonstruktor 

    a = b;                 // tilldelning genom kopiering

    a[5] = 7;              // tilldelning till element

    const UIntVector e(10);    // konstant objekt med 10 element
    
    int i = e[5];          // const int oper[](int) const körs
    i = a[0];              // vektorn är nollindexerad
    i = a[5];              // int oper[](int) körs
    
    a[5]++;                // öka värdet till 8
    
    try {
        i = e[10];             // försöker hämta element som ligger utanför e
    } catch (std::out_of_range e) {
        std::cout << e.what() << std::endl;
    }

    
#if 1
    // Diverse saker att testa
    //e[5] = 3;              // fel: (kompilerar ej) tilldelning till const
    b = b;                 // hmm: se till att inte minnet som skall behållas frigörs
#endif

    // UIntVector v = 3; ska ej gå 
    

    return 0;
}
