#pragma once
#include <iostream>
#include "Vertex.h"
#include <vector>

///klasa reprezentujaca figure/ksztalt
class FlatShape{

public:

  //konstruktor glosny ustawiajacy nazwe ksztaltu
  FlatShape(std::string name);

  //metoda dodajaca wierzcholki figury do pojemnika typu std::vector
  FlatShape& dodajW(const Vertex &v);

  //operator += dodajacy wierzcholki figury do pojemnika typu std::vector
  FlatShape& operator+=(const Vertex &v);

  //operator [] zwracajacy element pojemnika _arr typu Vertex& o zadanym indeksie 
  Vertex& operator[](int x){ return _arr[x]; }

  //metoda zwracajaca element pojemnika _arr typu Vertex& o zadanym indeksie 
  Vertex& giveout(int x){ return _arr[x]; }

  //metoda zwracajaca nazwe ksztaltu/figury
  std::string nazwa()const{ return _name; }

  //operator sprawdzajacy czy dwie figury sa takie same
  bool operator==(FlatShape& f);

  //operator zwracajacy rozmiar kontenera w ktorym przehcowywane są wierzcholki figury
  unsigned int size()const { return _arr.size(); }



private:
  //nazwa figury
  std::string _name;

  //kontener na wierzcholki figury
  std::vector<Vertex> _arr;
};

//operator << ktory wypisuje na ekran nazwe figury oraz jej wierzcholki
std::ostream& operator<<(std::ostream& strm, FlatShape &f);