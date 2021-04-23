#pragma once
#include <iostream>
#include "Primitive.h"

///klasa wykonujaca mnozenie, dziedziczaca po klasie primitive
class Product : public Primitive{

public:

  ///konstruktor
  Product(Primitive &a, Primitive &b): _a(a), _b(b){}

  /**
   * @brief - metoda wykonujaca operacje mnozenia
   * @return - wynik mnozenia typu float
   */
  float getX()const override{ return _a.getX() * _b.getX();}

  /**
   * @brief - metoda wypisujaca na ekran operacje która zostaje wykonana
   */
  void print()const override;

private:

/// referencja obiektu zawierajacego element operacji matematycznej
  Primitive &_a;

/// referencja obiektu zawierajacego element operacji matematycznej
  Primitive &_b;

};