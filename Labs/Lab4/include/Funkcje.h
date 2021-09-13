#pragma once
#include <iostream>
#include <cmath>

///klasa reprezentujaca sinusa
class Sinus{

public:

 /** Konstruktor ustawiajacy parametry f. sinus
   * @param [double] - a - pierwszy parametr
   * @param [double] - b - drugi parametr 
  */
  Sinus(const double a, const double b): _a(a), _b(b){}


 /** operator () wykonujacy operacje sinus
   * @par  [double] - x - parametr sinusa
   * @return  - zwraca wartosc operacji sinus w typie double
  */
  double operator()(const double x)const{ return sin(_a*x+_b);}

private:

  //zmienne przechowujace parametry sinusa
  const double _a,_b;
};


///klasa reprezentujaca pierwaistek kwadratowy
class PierwiastekKwadratowy{

public:

 /** operator () wykonujacy operacje pierwiastka
   * @par  [double] - x - liczba z ktorej liczony jest pierwaistek
   * @return  - zwraca wartosc pierwiastka w typie double
  */
  double operator()(const double x)const{ return sqrt(x);}

};


///klasa reprezentujaca funkcje liniowa
class Liniowa{

public:

 /** Konstruktor ustawiajacy parametry f. liniowej
   * @param [double] - a - wspolczynnik prostej
   * @param [double] - b - wyraz wolny prostej
  */
  Liniowa(const double a, const double b): _a(a), _b(b){}

 /** operator () wykonujacy obliczenia wartosci funkcji liniowej
   * @par  [double] - x - parametr obliczeniowy f. liniowej
   * @return  - zwraca wartosc obliczenia f.liniowej w typie double
  */
  double operator()(const double x)const{return _a*x+_b;}

private:

 //zmienne przechowujace parametry f.liniowej
  const double _a,_b;

};