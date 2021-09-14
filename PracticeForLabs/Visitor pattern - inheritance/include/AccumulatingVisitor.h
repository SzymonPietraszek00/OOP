#pragma once
#include <iostream>
#include "Visitor.h"
#include "ElData.h"

class AccumulatingVisitor : public Visitor{

public:
  
  float getTotalSum(){return _sum;}
  
  void visit(IntData* data){
    _sum += static_cast<float>(data->getValue()); 
  }
  
  void visit(FloatData* data){
    _sum += data->getFloat();
  }

private:
  float _sum = 0;

};