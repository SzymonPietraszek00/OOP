#include <iostream>
#include <string>
#include "include/FlatShape.h"
#include "include/Triangle.h"
#include "include/FSContainer.h"


/////////////////////////////////////////////////////////////////////////
int main(int argc, char * argv[]) {
    
    FlatShape f("x223");
    Triangle p("triang");
    
    const Vertex w1(1,1);
    const Vertex w2(4,1);
    const Vertex w3(4,4);
    
    std::cout << "Utworzone wierzcholki:" << w1 << w2 << w3 << std::endl;
    
    p.dodajW(w1).dodajW(w2).dodajW(w3);
    ((f += w1) += w2) += w3;
    
    std::cout << "Pole trojkata " << p.nazwa() << " wynosi " << p.pole() << std::endl;
    
    FlatShape f2("fff2");
    f2 += w2;
    f2.dodajW(w1);
    
    std::cout << "Test: " << (f==f2 ? "" : "nie") << "identyczne figury" << std::endl;
    
    FlatShape f3("fff3");
    ((f3 += w1) += w2) += w3;
    std::cout << "Test 2: " << (f==f3 ? "" : "nie") << "identyczne figury" << std::endl;
    
    std::cout << f3;
    
    FSContainer * const k = new FSContainer();
    *k += &f;
    *k += &p;
    *k += &f2;
    
    std::cout << *k;
    delete k;
}

/* //OUTPUT:
Jestem nowa figura x223
Jestem nowa figura triang
Mowiac scisle, jestem trojkatem.
Utworzone wierzcholki: <1, 1> <4, 1> <4, 4>
Pole trojkata triang wynosi 4.5
Jestem nowa figura fff2
Test: nieidentyczne figury
Jestem nowa figura fff3
Test 2: identyczne figury
Figura fff3: 
 <1, 1> <4, 1> <4, 4>
W kontenerze znajduja sie:
Figura x223: 
 <1, 1> <4, 1> <4, 4>
Figura triang: 
 <1, 1> <4, 1> <4, 4>
Figura fff2: 
 <4, 1> <1, 1>
*/
