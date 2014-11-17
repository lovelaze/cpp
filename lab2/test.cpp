#include "gregorian.h"
#include "julian.h"
#include <iostream>
#include "kattistime.h"
#include <cassert>

using namespace std;

struct A {
    virtual A & operator=(const A &) = 0; 

};

struct B : A{
    virtual A & operator=(const A &) = 0;
};

struct C : B{
    virtual C & operator=(const A &) {
        return *this;
    };

};


int main() {

    C c;


	
    

    
   
	return 0;
}
