#pragma once
#include <iostream>
#include "FlatShape.h"


///klasa reprezentujaca kontener na figury czyli na FlatShape
class FSContainer{
  
public:

  //operator += który dodaje do kontenera figury
  void operator+=(FlatShape *f){ _container.push_back(*f); }
  
  //metoda zwracajaca rozmiar kontenera
  unsigned size()const{ return _container.size(); }

  //operator [] zwracajacy figure z kontenera o zadanym indeksie
  FlatShape& operator[](unsigned x){ return _container[x]; }

private:

  //kontener przechowujacy figury
  std::vector<FlatShape> _container;
};

// operator wypisujacy wszystkie figury z kontenera 
std::ostream& operator<<(std::ostream& strm, FSContainer &f);