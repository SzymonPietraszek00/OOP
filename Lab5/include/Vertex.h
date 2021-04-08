#pragma once
#include <iostream>
#include "FlatShape.h"
#include <cmath>

//klasa reprezentujaca punkt
class Vertex{
  
public: 
  //konsturktor ustawiajacy wartosci punktu
  Vertex(int a, int b): _a(a), _b(b){}

  //zwraca wspolrzedna a punktu
  int getA()const{return _a;}

  //zwraca wspolrzedna b punktu
  int getB()const{return _b;}

  //metoda ktora zwraca odleglosc miedzy punktami
  double distance(Vertex &v){
    return double(sqrt(pow(abs(_a - v._a),2) + pow(abs(_b - v._b),2))) ;
  }

  //operator != ktory zwraca wartosc odpowiadajaca temu czy ddwa punkty są takie same
  bool operator!=(Vertex &v){

    if( (_a == v._a && _b == v._b) || (_a == v._b && _b == v._a) ) return 0;

    return 1;
  }



private:
  int _a, _b;
};


// operator << wypisujacy na ekran wszystkie figury
inline std::ostream& operator<<(std::ostream& strm, const Vertex &v){

  return strm << " <" << v.getA() << ", " << v.getB() << ">";
}