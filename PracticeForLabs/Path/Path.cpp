#include "Path.h"


std::ostream& operator<<(std::ostream& strm, const Path& p1){
  return strm << "Path(" << p1._link << ")";
}