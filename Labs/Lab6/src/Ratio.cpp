#include "Ratio.h"


void Ratio::print()const{  std::cout << "("; _a.print(); std::cout << "/"; _b.print(); std::cout << ")";  }