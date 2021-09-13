#pragma once
#include <iostream>
#include "Circle.h"
#include "Deltoid.h"
#include "Drawable.h"
#include "Point.h"
#include "Section.h"
#include "Transformable.h"
#include "ClosedShape.h"

inline void draw(Drawable *d){
  d->draw();
}