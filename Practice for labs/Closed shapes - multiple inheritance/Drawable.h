#pragma once
#include <iostream>
#include "Transformable.h"



class Drawable{

public:

  Drawable() = default;

  virtual ~Drawable() = default;

  virtual void draw() const = 0;

  virtual float length() const = 0;
  
};

