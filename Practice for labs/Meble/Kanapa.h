#pragma once
#include <iostream>
#include "Lozko.h"
#include "Sofa.h"

class Kanapa : public Sofa, public Lozko{

public:

   Kanapa(int sz, int wys, int dl, int siedzisko, int sz_spania): Mebel(sz,wys,dl),Sofa(siedzisko), Lozko(sz_spania){} 

  ~Kanapa(){
    std::cout << "~Kanapa" << std::endl;
  }

  std::ostream& print()const{
    std::cout << "jako ";
    Mebel::print();
    std::cout << std::endl << "  jako ";
    Sofa::print();
    std::cout << std::endl << "  jako ";
    return Lozko::print();
  }

private:

};