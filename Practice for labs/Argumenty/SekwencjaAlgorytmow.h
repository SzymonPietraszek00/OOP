#pragma once
#include <iostream>
#include <functional>
#include "Argumenty.h"
#include "Algs.h"
#include <vector>

class SekwencjaAlgorytmow{


public:

  void add(const std::function<Argumenty(Argumenty const&)> f){
    func.push_back(f);
  }

  Argumenty procesuj(const Argumenty& a){

    Argumenty ret(a);
    for(unsigned i = 0; i < func.size(); i++) {
      ret = func[i](ret);
    }

    return ret;
  }



private:
  std::vector<std::function<Argumenty(Argumenty const&)>> func;
  
};