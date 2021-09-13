#pragma once
#include <iostream>

///klasa repreznetujaca operacje matematyczna
class Primitive{

public:

  ///konstruktor domyslny
  Primitive() = default;

  ///konstruktor przyjmujacy wartosc typu float
  Primitive(float x): _x(x){}

  //destruktor
  virtual ~Primitive(){}

  /**
   * @brief - metoda wirtualna zwracajaca wartosc x
   * @return - wartosc x typu float
   */
  virtual float getX()const { return _x;}

  /**
   * @brief - metoda wirtualna wypisujaca na ekran wartosc x
   */
  virtual void print()const { std::cout << _x; }

  /**
   * @brief - metoda wypisujaca wszystko na ekran, wywoluje metode print() i getX()
   */
  void PrintWithValue()const;

  /** 
   * @brief - metoda ustawiająca nową wartość
   * @param[float] - nwoa wartość
   */ 
  void Set(float x){ _x = x;}

private:

  ///zmienna typu float przechowujaca wartosc
  float _x;

};