#pragma once
#include <iostream>
#include "Primitive.h"

///klasa wykonujaca dodawanie, dziedziczaca po klasie primitive
class Sum : public Primitive{

public:

  ///konstruktor
  Sum(Primitive &a, Primitive &b): _a(a), _b(b){}

   /**
   * @brief - metoda wykonujaca operacje dodawania
   * @return - wynik dodawania typu float
   */
  float getX()const override { return _a.getX() + _b.getX();}

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