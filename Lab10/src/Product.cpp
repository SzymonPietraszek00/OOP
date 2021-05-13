#include "Product.h"



void Product::print() const{
  
  std::cout << _name << ": ";

  std::for_each(_values.begin(), _values.end(), [](float x){

    std::cout << std::setw(6) << x;

  });

  std::cout << std::endl;
}