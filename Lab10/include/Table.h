#pragma once
#include <iostream>
#include "Product.h"

///klasa reprezentujaca "Tabelke", tablice dla obiektow typu product
class Table{

public:

//operator dodajacy produkty do kontenera
  void operator+=(Product p);

//metoda drukujaca
  void print()const;

//metoda sortujaca kontener o zadanym indeksie kolumny
  Table& sort(float x);

//metoda sortujaca malejąco elementy kontenera
  Table& sortBy(bool (&func)(const Product& p1, const Product& p2));

//zmienna przechowuajca informacje o najmniejszej ilosi danych w ktoryms z obiektow product znajdujacym sie w kontenerze 
  unsigned minRow = 15000;

private:

//przechowujaca obiekty typu product
  std::vector<Product> _table;


};