#pragma once
#include <iostream>
#include "Link.h"
#include <vector>


///klasa reprezentujaca katalog, slowo final uniemozliwiza dziedziczenie po tej klasie 
class Dir final : public Link{

public:

///konstruktor
  Dir(const std::string &name): Link(name) {}

///destruktor
  ~Dir();

///operator dodający katalog lub plik do kontenera
  void operator+=(Link *l){ _link.push_back(l); }

///metoda dodajaca katalog lub plik do kontenera
  void add(Dir *d){ *this += d; }

///metoda wyszukujaca i zwracajaca katalog o zadanej nazwie
  Dir* findDir(const std::string name);

///metoda zwracajaca katalog o zadanej nazwie 
  Link* get(const std::string name);

///metoda wypisujaca nazwy katalogow, przy uzyciu metody z klasy bazowej 
  void print(const int spaces)const override;


private:

///kontener
  std::vector<Link*> _link;

};