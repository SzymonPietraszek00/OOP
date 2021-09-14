#pragma once
#include <iostream>
#include "Pojazd.h"



class Motorowka : public virtual Pojazd{


public:

  Motorowka() = default;

  Motorowka(PredkoscMaksymalna pr): _pr(pr){

  }

  std::string predkoscMaksymalna() const{
    return std::to_string(_pr.Peer()) + " km/h";
  }

  void print() const override {
    std::cout << "Motorowka"; 
  }


private:
  PredkoscMaksymalna _pr;
};