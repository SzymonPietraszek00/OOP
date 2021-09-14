#pragma once
#include <iostream>

#include "Drawable.h"


class ClosedShape : public virtual Drawable{

public:
  virtual float area()const = 0;
  void draw() const override = 0;
};