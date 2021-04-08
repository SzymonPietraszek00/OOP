#pragma once
#include <iostream>
#include "FlatShape.h"
#include "Vertex.h"


/// klasa triangle dziedziczaca publicznie po flatshape
class Triangle : public FlatShape{

public:

  //konstruktor glosny ustawiajacy nazwe trojkata wykorzystujacy konstruktor klasy podstawowej
  Triangle(std::string name);

  //funkcja zwracajaca pole trojkata
  double pole();

};