/*
Celem zadania jest napisanie szablonu listy polaczonej.
Ma to byc najprostsza lista, to znaczy polaczona jednokierunkowo.
Z roznych operacji, ktore oferuje lista */

#include <string>
#include <utility>
#include <iostream>

#include "List.h"
int main() {
    List<int> l1;
    l1.add(1).add(6).add(6).add(11).add(7);
    std::cout << "orginal " << l1 << std::endl;
    List<int> l2 = l1;
    std::cout << "kopia " << l2 << std::endl;

    List<int> l3(std::move(l1));
    std::cout << "orginal po przesunieciu "<< l1 << std::endl;
    std::cout << "w nowym miejscu "<< l3 << std::endl;
    std::cout << "Jest 8? " << l3.contains(8) << " A jest 6? "<<l3.contains(6) << std::endl;


    List<std::string> s;
    s.add("Hello").add("darkness").add("my").add("old").add("friend");
    std::cout << s << std::endl;

    std::cout << s.pop() << std::endl;
    std::cout << s << std::endl;


    std::cout << l3.contains( [](int x){ return x > 5; }) << "\n";
    
    
}
/* wynik
orginal 1 6 6 11 7
kopia 1 6 6 11 7
orginal po przesunieciu
w nowym miejscu 1 6 6 11 7
Jest 8? 0 A jest 6? 1
Hello darkness my old friend
friend
Hello darkness my old
1
*/

