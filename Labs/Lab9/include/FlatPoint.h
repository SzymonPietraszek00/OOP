#pragma once
#include <iostream>
#include <cmath>

///klasa reprezentujaca punkt w ukladzie wspolrzednych
class FlatPoint{

public:

  ///konstruktor ustawiajacy wspolrzedne punktu oraz jego odleglosc od srodka ukladu wspolrzednych
  FlatPoint(int x, int y): _x(x), _y(y), _d(sqrt(pow(_x,2) + pow(y,2) )){}

/** 
  * @brief - operator porównujący odległości punktów od środka układu współrzędnych
  * @param - punkt w ukladzie wspolrzednych
  * @return - zwraca prawde jesli punkt pierwszy jest blizej srodka ukladu wspolrzednych w przeciwnym wypadku falsz 
  */
  bool operator<(const FlatPoint &f2)const;

  ///getter x
  int getX()const { return _x; }

  ///getter y
  int getY()const { return _y; }

/** 
  * @brief - metoda drukujaca wspolrzedne punktu oraz jego odleglosc od srodka ukladu wspolrzednych
  */
  void Print()const;

/** 
  * @brief - metoda statyczna drukujaca wspolrzedna Y punktu
  * @param - punkt ktorego wspolrzedna drukujemy
  */
  static void FunctionPrintY(const FlatPoint& point);


/** 
  * @brief - metoda statyczna drukujaca wspolrzedne punktu oraz jego odleglosc od srodka ukladu wspolrzednych
  * @param - punkt ktorego wspolrzedne drukujemy
  */
  static void PrintPoint(const FlatPoint& point);

private:

  //wspolrzedne x oraz y punktu
  int _x, _y;
  //odleglosc punktu od srodka ukladu wspolrzednych
  float _d;

};


///klasa - funktor
class OrderAscX{

public:

/** 
  * @brief - operator porównujący owspolrzedne x dwoch punktow
  * @param - [const FlatPoint &f1] punkt pierwszy 
  * @param - [const FlatPoint &f2] punkt drugi
  * @return - zwraca prawde jesli wspolrzedna x pierwszego punktu jest mniejsza od wspolrzednej x punktu drugiego
  */
  bool operator()(const FlatPoint &f1, const FlatPoint &f2)const{
    return f1.getX() < f2.getX();
  }


};


///klasa - funktor
class OrderDescY{

public:

/** 
  * @brief - operator porównujący owspolrzedne y dwoch punktow
  * @param - [const FlatPoint &f1] punkt pierwszy 
  * @param - [const FlatPoint &f2] punkt drugi
  * @return - zwraca prawde jesli wspolrzedna y pierwszego punktu jest wieksza od wspolrzednej y punktu drugiego
  */
  bool operator()(const FlatPoint &f1, const FlatPoint &f2)const{
    return f1.getY() > f2.getY();
  }

};


/** 
  * @brief - funkcja porownująca ze sobą większe wspolrzedne z pary danych punktow
  * @param - [const FlatPoint &f1] - punkt pierwszy 
  * @param - [const FlatPoint &f2] - punkt drugi
  * @return - zwraca prawde jesli wieksza wspolrzedna pierwszego punktu jest mniejsza od wiekszej wspolrzednej drugiego punktu
  */
bool MaxDistanceAsc(const FlatPoint &f1, const FlatPoint &f2);

/** 
  * @brief - funkcja wypisujaca wspolrzedna x punktu
  * @param - [const FlatPoint &point] - punkt 
  */
void FunctionPrintX(const FlatPoint& point);