#pragma once
#include <iostream>


class FloatData;
class IntData;

class Visitor{

public:

  Visitor() = default;
  virtual ~Visitor() = default;
  virtual void visit(IntData *data) = 0;
  virtual void visit(FloatData *data) = 0;


};