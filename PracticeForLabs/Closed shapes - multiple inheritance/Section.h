#pragma once
#include <iostream>
#include "Point.h"
#include <cmath>
#include "Drawable.h"
#include "Transformable.h"


class Section : public virtual Drawable,public Transformable{

public:

  Section(){}

  Section(Point p1, Point p2): _p1(p1), _p2(p2){}

  float length() const override{
    return sqrt (pow((_p1.getX() - _p2.getX()), 2) + pow((_p1.getY() - _p2.getY()), 2));
  }





  void draw() const override{
    std::cout << "Rysujemy odcinek od " << _p1 << " do " << _p2 << std::endl;
  }

  void shift(float x, float y) override{
    _p1.setX(x);
    _p2.setX(x);
    _p1.setY(y);
    _p2.setY(y);
  }

  Point pkt1()const{
    return _p1;
  }
  

  Point pkt2()const{
    return _p2;
  }


private:
  Point _p1, _p2;
  
};