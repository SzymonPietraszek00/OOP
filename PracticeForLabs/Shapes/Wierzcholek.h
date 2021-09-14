#pragma once
#include <iostream>
#include <cmath>


class Wierzcholek{

  friend std::ostream& operator<<(std::ostream& strm, const Wierzcholek &w);

public:
 Wierzcholek(int x, int y): _x(x), _y(y){}

  bool operator!=(const Wierzcholek w){

    return ((w._x == _x && w._y == _y) || (w._x == _y && w._y == _x))? 0 : 1; 
  }

  unsigned dist(const Wierzcholek w)const{

    return static_cast<unsigned> (sqrt(pow(abs( _x - w._x ) , 2) + pow(abs( _y - w._y ) , 2)));
  }

private:
  int _x, _y;
};



std::ostream& operator<<(std::ostream& strm, const Wierzcholek &w){

  return strm << "(" << w._x << ", " << w._y << ")";
}