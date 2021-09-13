#pragma once
#include <iostream>
#include "Link.h"

///klasa reprezentujaca plik
class File : public Link{

public:

///konstruktor
  File(const std::string &name): Link(name) {}

///destruktor
  ~File(){}

///metoda wypisujaca nazwy plikow, przy uzyciu metody z klasy bazowej
  void print(const int spaces)const override;
};