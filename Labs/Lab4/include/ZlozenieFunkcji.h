#pragma once
#include <iostream>
#include <functional>
#include <vector>


class ZlozenieFunkcji{

public:
  
  /** metoda umieszczająca zadaną funkcje do kontenera typu vector
   * @param  [std::function<double(double)>] - func - funkcja dodawana do kontenera 
   * @return  - void
   */
  void insert(std::function<double(double)> func){ _funct.push_back(func); }


  /** metoda umieszczająca zadaną funkcje do kontenera typu vector
   * @param  [double] - x - wartosc na ktorej wykonywane są operacje matematyczne 
   * @return [dobule] - zwraca wartosc wykonanych operacji, funkcjami znajdujacymi sie w kontenerze
   */
  double wynik(double x);


  /** operator [] zwracający elementy o zadanym indeksie
   * @param  [double] - x - indeks wyniki ktory chcemy wyciagnac
   * @return [dobule] - zwraca poszczegolne wartosci z kontenera _wyniki 
   */
  double& operator[](unsigned int x){ return _wyniki[x]; }

private:

  //kontener vector przechowujacy wyniki przeprowadzonych operacji
  std::vector<double> _wyniki;

  //kontener przechowujacy funkcje 
  std::vector<std::function<double(double)>> _funct;


};