#pragma once
#include <iostream>
#include "Mebel.h"

class Lozko : virtual public Mebel{

public:

   Lozko(int sz, int wys, int dl, int sz_spania): Mebel(sz,wys,dl), _sz_spania(sz_spania){} 

   Lozko(int szerSpan): _sz_spania(szerSpan){}

  ~Lozko(){
    std::cout << "~Lozko" << std::endl;
  }


  std::ostream& print()const override{

    std::cout << "Lozko: "; 
    
    Mebel::print();

    return std::cout << " sz.spania" << _sz_spania;
  }


private:
  int _sz_spania;
};