#pragma once
#include <iostream>
#include "Data.h"
#include <functional>
#include <numeric>

class Sum{

public:

  Sum(double x): _sum(x){}
  
  double value()const { return _sum; }

  void operator()(double x){
    _sum += x;
  }

private:
  double _sum = 0;

};

inline Sum sumData(const Data &d){

  return Sum(std::accumulate(d.getVal().begin(), d.getVal().end(), static_cast<double>(0.0)));
}