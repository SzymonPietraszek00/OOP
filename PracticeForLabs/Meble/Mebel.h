#pragma once
#include <iostream>

class Mebel{
  friend std::ostream& operator<<(std::ostream& strm, const Mebel& m);
public:
  Mebel(int sz, int wys, int dl): _sz(sz), _wys(wys), _dl(dl) {}

  Mebel(){}

  virtual ~Mebel(){
    std::cout << "~Mebel" << std::endl;
  }

  virtual std::ostream& print()const{
    return std::cout << "Mebel: sz:" << _sz << " wys:" << _wys << " dl:" << _dl;
  }

protected:
  int _sz, _wys, _dl;
};

std::ostream& operator<<(std::ostream& strm, const Mebel& m){

  return m.print();
}