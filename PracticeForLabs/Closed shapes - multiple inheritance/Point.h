#pragma once
#include <iostream>




class Point{

public:
  Point(float x = 0, float y = 0): _x(x), _y(y){}

  float getX()const noexcept{
    return _x;
  }

  float getY()const noexcept{
    return _y;
  }

  void setX(float x) noexcept{
    _x += x;
  }
  
  void setY(float y) noexcept{
    _y += y;
  }



private:
  float _x, _y;
  
};

inline std::ostream& operator<<(std::ostream& strm, const Point& p){

  return strm << "(" << p.getX() << ", " << p.getY() << ")";
}