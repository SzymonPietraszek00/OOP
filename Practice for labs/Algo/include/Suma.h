#pragma once
#include <iostream>
#include "Algo.h"


class Suma : public Algo{

public:
  
  Argumenty wykonaj(const Argumenty& a)const{
    Argumenty a2 ( 1 );

    for(int i = 0; i < a.getSize(); i++){
      a2.getArr()[0] += a.getArr()[i];
    }

    return a2;
  }

   Suma* sklonuj()const{
     return new Suma;
  }

};