#pragma once
#include <iostream>
#include "Visitor.h"
#include "ElData.h"



class PrintingVisitor : public Visitor{

public:
  PrintingVisitor() = default;
  

  void visit(IntData* data){
    std::cout << " " << data->getValue();
  }

  void visit(FloatData* data){
    std::cout << " " << data->getFloat();
  }



};