#pragma once
#include <iostream>
#include "Mebel.h"

class Sofa : virtual public Mebel{

public:

  Sofa(int sz, int wys, int dl, int siedzisko): Mebel(sz,wys,dl), _siedzisko(siedzisko){} 

  Sofa(int siedzisko): _siedzisko(siedzisko){}

  ~Sofa(){
    std::cout << "~Sofa" << std::endl;
  }

  std::ostream& print()const override{
    std::cout << "Sofa: " ;
    
    Mebel::print();
    
    return std::cout << " siedzisko: " << _siedzisko;
  }

private:
  int _siedzisko;
};

