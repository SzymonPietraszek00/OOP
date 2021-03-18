#include <iostream>
#include <utility>

#include "include/ReverseText.h"

int main() {
    ReverseText m(" am");
    m -= " I";
    m -= " as";
    m -= " bored";
    m -= " as";
    m -= " you";
    m -= " are";
    m -= " ?";

    std::cout << "size " << m.size() << " " << m.fragments() <<  " " << m << std::endl;

    ReverseText mm(std::move(m));
    std::cout << "m (after move) size " << m.size() <<  " " << m << std::endl;
    std::cout << "mm size " << mm.size() << " " << mm.fragments() <<  " " << mm << std::endl;

    ReverseText n(" ???");
    n -= std::move(mm);
    std::cout << "n: " << n << std::endl;

    ReverseText k;
    k = std::move(n);
    std::cout << "n (after move): " << n << std::endl;
    std::cout << "k: " << k << std::endl;
    const ReverseText kk(std::move(k));
    std::cout << "kk: " << kk.fragments() << std::endl;
    std::cout << kk.fragment(4).str() << std::endl;
}

/* //Output:
size 27 8  ? are you as bored as I am
m (after move) size 0 
mm size 27 8  ? are you as bored as I am
n:  ? are you as bored as I am ???
n (after move): 
k:  ? are you as bored as I am ???
kk: 9
 bored
*/
