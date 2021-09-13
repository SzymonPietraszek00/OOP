#include "Link.h"


void Link::print(const int spaces) const{
  for(int i  = 0; i < spaces; i++) std::cout << " ";
  std::cout << _name;
}