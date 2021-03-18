#pragma once
#include <iostream>
#include <cstring>
#include <utility>


class ReverseText{

//zaprzyjazniony operator wypisywania
  friend std::ostream& operator<<(std::ostream& strm, const ReverseText &r);

public:

//konstruktor przyjmujący tekst do wpisania
  ReverseText(const char* txt ="");

//destruktor
  ~ReverseText();

//konsturktor kopiujący
  ReverseText(const ReverseText& r):  _txt(r._txt), _len(r._len), _next(r._next){}
  
//konstruktor przenoszący
  ReverseText(ReverseText&& r ):  _txt(std::exchange(r._txt,nullptr)),_len(std::exchange(r._len,0)), _next(std::exchange(r._next,nullptr)){}

//operator dodający tekst do listy
  void operator-=(const char *txt);

//operator przenoszący tekst do listy
  void operator-=(ReverseText&& r){_next = &r;}

//operator przypisujacy tekst do listy
  void operator=(ReverseText&& r);

//metoda zwracajaca dane slowo listy
  const char* str()const{return _txt;}

//metoda zwracajaca ilosc liter
  int size()const;

//metoda zwracajaca ilosc slow
  int fragments()const;

//metoda zwracajaca slowo o zadanym indeksie w zdaniu
  const ReverseText fragment(unsigned int x)const;

private:

//zmienna typu wskanzik przechowuajca slowo
  char *_txt = nullptr;

//dlugosc slowa
  unsigned int _len = 0;

//wskaznik na nastepne slowo
  ReverseText *_next = nullptr;

};