#pragma once
#include <iostream>
#include "Section.h"
#include "ClosedShape.h"


class Deltoid: public virtual ClosedShape, public Transformable{


public:

  Deltoid(Section s1, Section s2): _s1(s1), _s2(s2){}

  Deltoid(Point p1, Point p2, Point p3, Point p4): _s1(p1, p3), _s2(p2, p4){
  }


  float area()const override{
    return _s1.length() * _s2.length();
  }

  void draw() const override{
    std::cout << "Rysujemy deltoid o wierzcholkach " << _s1.pkt1() << " " << _s2.pkt1() <<  " " << _s1.pkt2() << " " << _s2.pkt2() << std::endl;
  }


  void shift(float x, float y) override{
    _s1.shift(x, y);
    _s2.shift(x, y);
  }

  float length() const override{
    Section b1(_s1.pkt1(), _s2.pkt1());
    Section b2(_s1.pkt1(), _s2.pkt2());
    Section b3(_s1.pkt2(), _s2.pkt1());
    Section b4(_s1.pkt2(), _s2.pkt2());

    return b1.length() + b2.length() + b3.length() + b4.length();
  }

private:
  Section _s1, _s2;
  
};