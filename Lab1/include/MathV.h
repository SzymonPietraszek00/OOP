#pragma once
#include <iostream>
#include <cmath>

///klasa opisująca wektor
class MathV{

  /**
   * funkcja zaprzyjazniona wykonująca operacje dodawania i przypisania
   * @param[const MathV&] - wektor pierwszy 
   * @param[const MathV&] - wektor drugi 
   * return - zwraca wektor na ktorym operacje jest wykonana
  */
  friend MathV operator+=(const MathV& v1, const MathV& v2);

  /**
   * funkcja zaprzyjazniona wykonująca operacje dodawania i przypisania
   * @param[const MathV&] - wektor pierwszy 
   * @param[int x] - wektor drugi 
   * return - zwraca wektor na ktorym operacje jest wykonana
  */
  friend MathV operator+=(const MathV& v1, int x);
  
public:

  /**
   * konstruktor wypelniajacy wektor zerami
   * @param [unsigned int] - rozmiar wektora
  */
  explicit MathV(unsigned int);

  /**
   * destruktor usuwajacy wektor i ustawiajacy wskaznik na null
  */
  ~MathV();

  /**
   * konstruktor kopiujacy
  */
  MathV(const MathV&);

  /**
   * konstruktor przenoszacy
  */
  MathV(MathV&&);

  /**
    * funkcja zwracajaca element wektora o indeksie x
    * @param[unsigned int] - indeks wektora
    * return - wartosc wektora pod danym indeksem typu int
   */
  int& at(unsigned int x)const{return _arr[x];}

  /**
    * funkcja drukujaca wektor
    * @param [std::string] - nazwa wektora
   */
  void print(std::string)const;


  /**
    * funkcja wyliczająca iloczyn skalarny dwoch wektorow
    * @param[MathV v1] - pierwszy wektor
    * @param[MathV v2] - drugi wektor
    * return - zwraca iloczyn skalarny w postaci typu double
   */
  static double dot(MathV v1,MathV v2);

  /**
    * funkcja wyliczająca norme wektora
   */
  double norm()const{return sqrt(dot(*this,*this));}
  
  /**
    * operator konwertujacy klase na double
    * return - zwraca norme wektora
   */
  operator double()const{return norm();}


private:

  /**
    * @param [unsigned int] - parametr - rozmiar wektora
   */
  unsigned int _size;

  /**
    * @param [int] - wskaznik typu int - nasz wektor
   */
  int *_arr;

};