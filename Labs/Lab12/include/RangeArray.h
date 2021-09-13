#pragma once
#include <iostream>
#include "PairOfNumbers.h"

///szablon klasy range array reprezentujacej tablice
template<typename T>
class RangeArray{

public:

///konstruktor
  RangeArray(PairOfNumbers<int, T>& p): _size(p.second - p.first), _arr(new T[_size]){}

///destruktor
  ~RangeArray(){delete [] _arr;}

///konstruktor kopiujacy
  RangeArray(const RangeArray& r): _size(r._size), _arr(new T[_size]){
    for(unsigned i = 0; i < _size; i++){
      _arr[i] = r._arr[i];
    }
  }

///(getter) - metoda zwracajaca rozmiar tablicy
  unsigned Size()const { return _size; }

///przeciazany operator [] zwracajacy element tablicy o zadanym indeksie
  T& operator[](int x){ 
    if(x<0) x = _size + x;
    return _arr[x]; 
 }

///metoda zwracajaca element tablicy o zadanym indeksie
  T& At(int x)const { 

    if(x<0) x = _size + x;
    return _arr[x]; 
  }

private:

///rozmiar tablicy
  unsigned _size;
///tablica zadanego typu
  T *_arr;

};