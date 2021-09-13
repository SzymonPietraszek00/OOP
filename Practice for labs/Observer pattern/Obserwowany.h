#pragma once
#include <iostream>
#include "Obserwator.h"
#include <vector>

class Obserwowany{

public:

  void noweDaneNadeszly(int x){
    for(unsigned i = 0; i < _arr.size(); i++) {
      _arr[i]->dodajDane(x);
    }
  }

  void dodajObserwatora(Obserwator* o){
    _arr.push_back(o);
  }


private:
  std::vector<Obserwator*> _arr;
  int _x;
};