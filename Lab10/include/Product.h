#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

///klasa repreznetujaca produkt
class Product{

public:

///konstruktor z lista inicjalizacyjna
  Product(std::string name, std::vector<float> values): _name(name), _values(values){}

///metoda drukujaca nazwe i wartosci kontenera
  void print() const;

//getter do kontenera
  const std::vector<float>& getVal() const { return _values; }

private:

//zmienna przechowujaca nazwe produktu
  std::string _name;

//kontener przechowujacy wartosci produktu
  std::vector<float> _values;

};