#pragma once
#include <iostream>
#include <cstddef> 
#include <string> 




class Path{

friend std::ostream& operator<<(std::ostream& strm, const Path&);

public:

  enum system{
    UNIX,
    WIN
  };

  Path(std::string link, system sys = UNIX): _link(link), _sys(sys){}

  std::string str() const{ return _link;}

  std::string parent() const{ 
    std::size_t found = _link.find_last_of("/");

    return _link.substr(0,found);
  }

  Path operator/(std::string s1) const{ 
    if(_sys == UNIX){
      return Path(_link + "/" + s1);
    }
    return Path(_link + "\\" + s1, WIN);
  }

  void reset(system sys){
    if(sys != _sys){
      for(unsigned int i = 0; i < _link.length();i++){
        if(_link[i] == '\\'){_link[i]='/';}
      }
    }
  }

  std::string _link;
  system _sys;
};