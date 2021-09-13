#pragma once
#include <iostream>
#include "Visitor.h"

class Data{
public:
  

};


class FloatData: public Data {

public:

  FloatData(float value):_value(value){}

  void acceptVisitor(Visitor &v1 ){ 
    v1.visit(this);
  }

  void operator<<( float value ) { _value = value; }

  float getFloat()const{return _value;}


private:
  float _value;

}; 

class IntData : public Data{

public:
  IntData(int value):_value(value){}

  void acceptVisitor(Visitor &v1 ){
    v1.visit(this);
  }

  void operator<<( int value ) { _value = value; }

  int getValue()const{return _value;}

private:
  int _value;

}; 
