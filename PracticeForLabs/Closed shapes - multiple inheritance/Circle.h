#pragma once
#include <iostream>
#include "Point.h"
#include "ClosedShape.h"
#include <cmath>


class Circle: public virtual ClosedShape, public Transformable{

public:
  Circle(Point p, float r): _p(p), _r(r){}

  float area() const override{
    return M_PI * _r * _r;
  }
  
  void draw() const override{
    std::cout << "Rysujemy kolo o srodku " << _p << " i promieniu " << _r << std::endl;
  }


  void shift(float x, float y) override{
    _p.setX(x);
    _p.setY(y);
  }

  float length() const override{
    return 2 * M_PI * _r;
  }

private:
  Point _p;
  float _r;


};