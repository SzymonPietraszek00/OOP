#include <iostream>

#include <type_traits> // Dla std::is_pod i std::integral_constant 
#include <vector>
#include <deque>

struct A {};
struct A_ { virtual ~A_() {} };

template <typename T>
struct Is_Pod{};

template<>    //specjalizacja dla typu A
struct Is_Pod<A>{
    static void print(){std::cout << "Copying POD objects" << std::endl;}
};

template<>    //specjalizacja dla typu A_
struct Is_Pod<A_>{
    static void print(){std::cout << "Copying non-POD objects" << std::endl;}
};


template <typename InputIterator, typename DestIterator>
void my_copy(InputIterator kopac, InputIterator prowadzacego, DestIterator w_czolo){
    Is_Pod<typename InputIterator::value_type>::print();
}




int main()  {
//prosze wykorzystac te informacje
std::integral_constant<bool,true> tA = std::is_pod<A>::type();
std::integral_constant<bool,false> tA_ = std::is_pod<A_>::type();

//Iterator dla każdego kontenera ma zdefiniowany 
//typ value_type określający typ obiektu na który wskazuje
std::deque<A> vA1;
std::vector<A> vA2;
my_copy(vA1.begin(), vA1.end(), vA2.begin() ) ;

std::vector <A_> vA_1;
std::deque<A_> vA_2;
my_copy(vA_1.begin(), vA_1.end(), vA_2.begin() ) ;
}

/* output/wyjscie 
Copying POD objects
Copying non-POD objects
*/ 
