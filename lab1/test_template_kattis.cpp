//#include "Vector.h"             // inkludera din headerfil här
#include "kth_cprog_template_container.hpp"
#include <assert.h>             // assert(b) ger felmeddelande om b falsk


using namespace std;
    
int main()
{
    Vector<double> a (1000 ,1024);           // ok: defaultkonstruktor ger vektor med flyttal
    a.push_back(2048);
    assert(a._capacity >= 1001);
    a.insert(0, 123);
    a.insert(2, 1337);
    a.insert(5, 123);
    assert(*a.end() == 1024);
    assert(*a.begin() == 123);
    a.clear();
    assert(a.begin() == a.end());
    assert(*a.find(1337) != 1337);
    try {
        a.erase(99999);
    } catch (std::out_of_range e) {
        std::cout << e.what() << std::endl;
    }
    a.push_back(55);
    a.push_back(56);
    a.insert(1,321);
    a.insert(1,321);
    a.insert(1,321);
    a.insert(1,321);
    a.insert(1,321);
    a.insert(1,321);
    a.insert(1,321);
    a.insert(0, 55);
    assert(a.size() == 10); 

    
    a[0] = 1;
    a[3] = 4;

    try {
        a[10] = 1;
    } catch (std::out_of_range e) {
        std::cout << e.what() << std::endl;
    }
    try {
        a[99999] = 5;
    } catch (std::out_of_range e) {
        std::cout << e.what() << std::endl;
    }

    assert(a.size() == 10); 
    assert(a[0] == 1);
    assert(a[3] == 4);
    try {
        assert(a[10] == 1);
    } catch (std::out_of_range e) {
        std::cout << e.what() << std::endl;
    }
    try {
        assert(a[99999] == 5);
    } catch (std::out_of_range e) {
        std::cout << e.what() << std::endl;
    }

    assert(a.size() == 10);
    a.reset();

    Vector<int> b;
    b.push_back(1);
    b.push_back(2);
    b.insert(0, 3);
    assert(b._capacity > 3);
    b.clear();
    assert(b._capacity > 3);
    assert(b.size() == 0);


    Vector<int> v (2, 5);
    cout << v._capacity << endl;
    v.push_back(5);
    v.push_back(5);
    v.push_back(5);
    cout << v._capacity << endl;
    v.print();


    const Vector<int> v2 {1,2,3};

    auto beg = v2.begin();

    cout << beg << endl;
    //*beg = 5;


    Vector<int> v3 {1,2,3};
    *v3.begin() = 3;


     std::cout << "int: " << std::is_move_assignable<int>::value << std::endl;

    return 0;
}
