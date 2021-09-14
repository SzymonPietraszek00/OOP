#pragma once
#include <iostream>
#include "Motorowka.h"
#include "Samochod.h"


//po motorowce i samochodzie
class Amfibia : public Motorowka, public Samochod{


public:

  ~Amfibia() = default;

  Amfibia(PredkoscMaksymalna pr1, PredkoscMaksymalna pr2): Motorowka(pr2), Samochod(pr1){}

  std::string predkoscMaksymalna_Lad(){
    
    return Samochod::predkoscMaksymalna();
  
  }

  std::string predkoscMaksymalna_Woda(){

    return Motorowka::predkoscMaksymalna();

  }

  void print() const override {
    std::cout << "Amfibia"; 
  }



private:

};