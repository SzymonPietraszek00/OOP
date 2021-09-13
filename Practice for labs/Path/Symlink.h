#pragma once
#include <iostream>
#include <cstddef> 
#include <string> 
#include "Path.h"


class Path;

class Symlink{
  friend  std::ostream& operator<<(std::ostream& strm, const Symlink& s1);

public:
  
  Symlink(std::string sym, Path *p1 ): _symlink(sym){ 
    p_link = p1->_link; 
  }

 

  std::string str() const{ return p_link;}

  std::string parent() const{ 
    std::size_t found = p_link.find_last_of("/");

    return p_link.substr(0,found);
  }

  const Symlink* operator->() const { return this;}


private:
  std::string p_link;
  std::string _symlink;

};