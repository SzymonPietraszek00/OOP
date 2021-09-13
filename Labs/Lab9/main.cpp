/*Proszę napisać klasę FlatPoint, która będzie przechowywała dwie współrzedne punktu: x i y. Każdy punkt ma również odleglość od środka układu współrzędnych (funkcja sqrt znajduje się w pliku cmath). Proszę dopisać możliwość porównywania punktów na podstawie odległości od środka układu współrzędnych - potrzebny jest operator mniejszości.

Klasa FlatPoint powinna zawierać również dwie metody statyczne: PrintPoint(const FlatPoint& point), która wypisuje na ekran informacje o obiekcie point i FunctionPrintY(const FlatPoint& point), która wypisuje na ekran tylko współrzędną Y punktu.

Funkcja MaxDistanceAsc powinna zwracać prawdę, jeżeli większa ze współrzędnych pierwszego punktu jest mniejsza od większej współrzędnej drugiego punktu. Czyli należy sprawdzić czy x czy y jest większy dla pierwszego punktu, następnie powtórzyć to samo dla współrzędnych drugiego punktu i zwrócić prawdę, jeżeli wartość dla pierwszego punktu jest mniejsza od wartości dla drugiego punktu.

Należy dopisać również dwie klasy-funktory:
OrderAscX - porównuje dwa punkty na podstawie tylko współrzędnej X,
OrderDescY - porównuje dwa punkty tylko na podstawie współrzędnej Y.

Ostatnią funkcją do zaimplementowania jest FunctionPrintX(const FlatPoint& point), która wypisuje na ekran wspolrzędną X punktu.

Proszę cały kod umieścić w plikach FlatPoint.h oraz FlatPoint.cpp.*/

#include "include/FlatPoint.h"
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main(){
  using namespace std;

  FlatPoint pointsArray [] = {FlatPoint(0, 0), FlatPoint(3, 2), FlatPoint(4, 4), FlatPoint(2, 3), FlatPoint(1, 5)};
  const int pointsArraySize = sizeof(pointsArray)/sizeof(FlatPoint);

  cout << "===== POINTS =====\n";
  set<FlatPoint> points;
  points.insert(pointsArray, pointsArray + pointsArraySize);

  for (set<FlatPoint>::iterator it = points.begin(); it != points.end(); ++it)
    it->Print();

  cout << "===== POINTS ascending X =====\n";
  set<FlatPoint, OrderAscX> pointsAscX;
  pointsAscX.insert(pointsArray, pointsArray + pointsArraySize);
  for (set<FlatPoint, OrderAscX>::iterator it = pointsAscX.begin(); it != pointsAscX.end(); ++it)
    it->Print();
  
  cout << "===== POINTS descending Y =====\n";
  set<FlatPoint, OrderDescY> pointsDescY;
  pointsDescY.insert(pointsArray, pointsArray + pointsArraySize);
  for (set<FlatPoint, OrderDescY>::iterator it = pointsDescY.begin(); it != pointsDescY.end(); ++it)
    it->Print();
  
  cout << "===== POINTS max(x, y) =====\n";
  bool(*maxMetricsAsc)(const FlatPoint&, const FlatPoint&) = MaxDistanceAsc;
  set<FlatPoint, bool(*)(const FlatPoint&, const FlatPoint&)> pointsMax (maxMetricsAsc);
  pointsMax.insert(pointsArray, pointsArray + pointsArraySize);
  for (set<FlatPoint, bool(*)(const FlatPoint&, const FlatPoint&)>::iterator it = pointsMax.begin(); it != pointsMax.end(); ++it)
    it->Print();

  cout << "===== POINTS vector =====\n";
  vector<FlatPoint> pointsVector;
  pointsVector.insert(pointsVector.begin(), pointsArray, pointsArray + pointsArraySize);

  cout << "----- print X -----\n";
  for_each(pointsVector.begin(), pointsVector.end(), FunctionPrintX);

  cout << "----- print Y -----\n";
  for_each(pointsVector.begin(), pointsVector.end(), FlatPoint::FunctionPrintY);

  cout << "----- sorted Y -----\n";
  OrderDescY descY;
  sort(pointsVector.begin(), pointsVector.end(), descY);
  for_each(pointsVector.begin(), pointsVector.end(), FlatPoint::FunctionPrintY);
  
  cout << "===== FOR EACH =====\n";
  cout << "----- set -----\n";
  for_each(pointsAscX.begin(), pointsAscX.end(), FlatPoint::PrintPoint);

  cout << "----- array -----\n";
  for_each(pointsArray, pointsArray + pointsArraySize, FlatPoint::PrintPoint);

  return 0;
}

/* //Output:
===== POINTS =====
Point coordinates (0, 0) distance from origin: 0
Point coordinates (3, 2) distance from origin: 3.60555
Point coordinates (1, 5) distance from origin: 5.09902
Point coordinates (4, 4) distance from origin: 5.65685
===== POINTS ascending X =====
Point coordinates (0, 0) distance from origin: 0
Point coordinates (1, 5) distance from origin: 5.09902
Point coordinates (2, 3) distance from origin: 3.60555
Point coordinates (3, 2) distance from origin: 3.60555
Point coordinates (4, 4) distance from origin: 5.65685
===== POINTS descending Y =====
Point coordinates (1, 5) distance from origin: 5.09902
Point coordinates (4, 4) distance from origin: 5.65685
Point coordinates (2, 3) distance from origin: 3.60555
Point coordinates (3, 2) distance from origin: 3.60555
Point coordinates (0, 0) distance from origin: 0
===== POINTS max(x, y) =====
Point coordinates (0, 0) distance from origin: 0
Point coordinates (3, 2) distance from origin: 3.60555
Point coordinates (4, 4) distance from origin: 5.65685
Point coordinates (1, 5) distance from origin: 5.09902
===== POINTS vector =====
----- print X -----
Function print x=0
Function print x=3
Function print x=4
Function print x=2
Function print x=1
----- print Y -----
Function print y=0
Function print y=2
Function print y=4
Function print y=3
Function print y=5
----- sorted Y -----
Function print y=5
Function print y=4
Function print y=3
Function print y=2
Function print y=0
===== FOR EACH =====
----- set -----
Point coordinates (0, 0) distance from origin: 0
Point coordinates (1, 5) distance from origin: 5.09902
Point coordinates (2, 3) distance from origin: 3.60555
Point coordinates (3, 2) distance from origin: 3.60555
Point coordinates (4, 4) distance from origin: 5.65685
----- array -----
Point coordinates (0, 0) distance from origin: 0
Point coordinates (3, 2) distance from origin: 3.60555
Point coordinates (4, 4) distance from origin: 5.65685
Point coordinates (2, 3) distance from origin: 3.60555
Point coordinates (1, 5) distance from origin: 5.09902
*/
