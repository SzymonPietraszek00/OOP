#include "Symlink.h"


 std::ostream& operator<<(std::ostream& strm, const Symlink& s1){
    return strm << "Symlink(" << s1._symlink << ")";
  }