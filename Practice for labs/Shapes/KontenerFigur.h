#pragma once
#include <iostream>
#include <vector>
#include "Figura.h"

class KontenerFigur{

   friend std::ostream& operator<<(std::ostream& strm, const KontenerFigur &k);

public:

  void operator+=(Figura *f){
    _kontener.push_back(f);
  }



private:
  std::vector<Figura*> _kontener;
};


std::ostream& operator<<(std::ostream& strm, const KontenerFigur &k){
  
  for(unsigned i = 0; i < k._kontener.size(); i++){
    strm << *k._kontener[i];
  }

  return strm;
}