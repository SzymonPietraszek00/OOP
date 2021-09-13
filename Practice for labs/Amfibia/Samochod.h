#pragma once
#include <iostream>
#include "Pojazd.h"


//po pojezdzie ladowym
class Samochod : public PojazdLadowy{


public:

  Samochod(){}

  ~Samochod() = default;

  Samochod(PredkoscMaksymalna &pr): _pr(pr){}

  void print() const override {
    std::cout << "Samochod"; 
  }

  std::string predkoscMaksymalna() const{
    return std::to_string(_pr.Peer()) + " km/h";
  }


private:
  PredkoscMaksymalna _pr;

};