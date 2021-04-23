#pragma once
#include <iostream>


///klasa bazowa dla katalogu i pliku czyli klasy Dir i File
class Link{

public:

///konstruktor
  Link(const std::string &name): _name(name) {}

///destruktor wirtualny domyślny
  virtual ~Link() = default;

///wirtualna metoda wypisujaca
  virtual void print(const int spaces = 0) const;

///metoda zwracajaca nazwe pliku lub katalogu
  const std::string getName()const{ return _name; }

private:

///zmienna przechowujaca nazwe pliku lub katalogu
  std::string _name;
};

///przeciazony operator wypisywania
inline std::ostream& operator<<(std::ostream& strm, const Link& l){

  l.print();
  return strm;
}