#pragma once
#include <iostream>
#include <cmath>
#include "Algo.h"

class Pierwiastek : public Algo{

public:
  
  Argumenty wykonaj(const Argumenty& a)const {
    Argumenty a2 ( a.getSize() );
    
    for(int i = 0; i < a.getSize(); i++){
      a2.getArr()[i] = sqrt(a.getArr()[i]);
    }

    return a2;
  }

  Pierwiastek* sklonuj()const{
    return new Pierwiastek;
  }

};