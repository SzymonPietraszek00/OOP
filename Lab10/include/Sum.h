#pragma once
#include <iostream>
#include "Product.h"
#include <numeric>

/// klasa przechowujaca sume wartosci 
class Sum{

public:

///konstruktor
  Sum(float x): _suma(x){}

//getter sumy
  float value()const{ return _suma; }

//operator () zwracajacy sumę powiększoną o zadany argument x
  void operator()(float x){ _suma += x; }

private:

//zmienna przechowuajaca sume
  float _suma = 0;

};

///funkcja wyznaczajaca sume 
Sum sumData(const Product &p);