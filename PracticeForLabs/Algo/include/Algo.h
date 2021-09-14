#pragma once
#include "Argumenty.h"

class Algo{

public:
  
  virtual ~Algo() = default;
  virtual Argumenty wykonaj(const Argumenty& a)const = 0;
  virtual Algo* sklonuj()const = 0;

};