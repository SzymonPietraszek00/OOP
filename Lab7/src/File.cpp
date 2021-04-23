#include "File.h"


void File::print(const int spaces)const{

  Link::print(spaces);
  std::cout << " (FILE)" << std::endl;
}