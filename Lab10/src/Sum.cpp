#include "Sum.h"



Sum sumData(const Product &p){

  return Sum(std::accumulate(p.getVal().begin(), p.getVal().end(), static_cast<float>(0.0)));
}