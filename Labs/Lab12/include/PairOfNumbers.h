#pragma once
#include <iostream>

///szablony klasy reprezentujacej pare liczb
template<typename T1, typename T2>
class PairOfNumbers{

public:

///konstruktor
  PairOfNumbers(T1 &one, T2 &two): first(one), second(two){}

///metoda zamieniajaca kolejnosc liczb w parze
  auto Swapped()const { 
    return PairOfNumbers<T2, T1>(second,first); 
  }

///metoda drukujaca pare liczb
  void Print()const { std::cout << "Print method: " << first << " " << second << std::endl; }

///metoda dodajaca liczbe do kazdej z liczb pary
  void Add(T1 x){ first += x; second +=x;  }

///metoda mnozaca kazda liczbe z pary przez liczbe zadaną
  void Scale(T1 x){ first *= x; second *=x;  }

///metoda informujaca ze obiekt(para) nie jest const
  void Info(){ std::cout << "This is NON-const pair of numbers\n"; }
///metoda informujaca ze obiekt(para) jest const
  void Info()const{ std::cout << "This is const pair of numbers\n"; }

///referencja do pierwszej liczby z pary
  T1 &first;
///referencja do drugiej liczby z pary
  T2 &second;


};