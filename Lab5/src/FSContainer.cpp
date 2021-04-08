#include "FSContainer.h"



std::ostream& operator<<(std::ostream& strm, FSContainer &f){

  std::cout << "W kontenerze znajduja sie: " << std::endl;

   for(unsigned i = 0; i < f.size(); i++){
    strm << f[i];
   }

  return strm;
}