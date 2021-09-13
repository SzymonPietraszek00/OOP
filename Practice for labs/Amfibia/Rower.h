#pragma once
#include <iostream>
#include "Pojazd.h"

// po pojezdzie ladowym
class Rower : public PojazdLadowy{


public:

  ~Rower() = default;

  void print() const override {
    std::cout << "Rower"; 
  }


private:

};