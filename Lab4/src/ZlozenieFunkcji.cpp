#include "ZlozenieFunkcji.h"


double ZlozenieFunkcji::wynik(double x){

    _wyniki.clear();

    for(unsigned int i = 0;i < _funct.size(); i++){
      
      x = _funct[i](x);
      _wyniki.push_back(x);
    }

    return x;
}