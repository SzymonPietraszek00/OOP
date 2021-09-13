#include "Product.h"


void Product::print()const{  std::cout << "("; _a.print(); std::cout << "*"; _b.print(); std::cout << ")";  }