#pragma once
#include <iostream>
#include "PredkoscMaksymalna.h"


class Pojazd{


public:

  virtual void print() const = 0;

  virtual ~Pojazd() = default;

private:

};

inline std::ostream& operator<<(std::ostream& strm, const Pojazd &p){

  p.print();
  return strm;
}