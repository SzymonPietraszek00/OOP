#pragma once
#include <iostream>
#include <functional>
#include "Funkcje.h"
#include <vector>


class ZlozenieFunkcji{

public:
  void insert(std::function<double(double)> x){ _vect.push_back(x);}

  double wynik(double x){
    
   _result.clear();

    for(unsigned i=0; i < _vect.size(); i++){

      x = _vect[i](x);
      _result.push_back(x);
    }


    return x;
  }

  double operator[](unsigned x){return _result[x];}

private:

  std::vector<double> _result;

  std::vector<std::function<double(double)>> _vect;
};