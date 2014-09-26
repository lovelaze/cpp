#include <iostream>
#include <stdexcept>
#include "UIntVector.h"     // inkludera din headerfil h�r

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

    //N�gra saker som ska fungera:
    UIntVector a(7);           // initiering med 7 element
    UIntVector b(a);           // kopieringskonstruktor 
    UIntVector c = a;          // kopieringskonstruktor 

    a = b;                 // tilldelning genom kopiering

    a[5] = 7;              // tilldelning till element

    const UIntVector e(10);    // konstant objekt med 10 element
    
    int i = e[5];          // const int oper[](int) const k�rs
    i = a[0];              // vektorn �r nollindexerad
    i = a[5];              // int oper[](int) k�rs
    
    a[5]++;                // �ka v�rdet till 8
    
    try {
        i = e[10];             // f�rs�ker h�mta element som ligger utanf�r e
    } catch (std::out_of_range e) {
        std::cout << e.what() << std::endl;
    }

    
#if 1
    // Diverse saker att testa
    //e[5] = 3;              // fel: (kompilerar ej) tilldelning till const
    b = b;                 // hmm: se till att inte minnet som skall beh�llas frig�rs
#endif

    // test initalizer list
    UIntVector v {1,2,3,4};
    UIntVector v1(v);
    std::cout << v.size() << std::endl;
    std::cout << v1.size() << std::endl;
    UIntVector v2;
    printVector(v);
    printVector(v1);
    v1[2] = 13;
    printVector(v);
    printVector(v1);
    std::cout << v2.size() << std::endl;
    
    
    return 0;
}
