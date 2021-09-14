#pragma once
#include <iostream>
#include <cmath>


class Sinus{

public:

  Sinus(double a, double b): _a(a), _b(b){}

  double operator()(double x)const{return sin(_a*x +_b);}

private:
  double _a, _b;

};


class PierwiastekKwadratowy{

public:
  double operator()(double x)const{return sqrt(x);}
};


class Liniowa{

public:

  Liniowa(double a, double b): _a(a), _b(b){}
  double operator()(double x)const{return _a*x + _b;}

private:
  double _a,_b;

};