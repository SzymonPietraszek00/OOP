#include "FlatPoint.h"


bool FlatPoint::operator<(const FlatPoint &f2)const{
  return _d < f2._d;
}

void FlatPoint::FunctionPrintY(const FlatPoint& point){
  std::cout << "Function print y=" << point.getY() << std::endl;
}


void FlatPoint::PrintPoint(const FlatPoint& point){
  point.Print();
}

void FlatPoint::Print()const{
  std::cout << "Point coordinates (" << _x << ", " << _y << ") distance from origin: " << _d << std::endl;
}

void FunctionPrintX(const FlatPoint& point){
  std::cout << "Function print x=" << point.getX() << std::endl;
}


bool MaxDistanceAsc(const FlatPoint &f1, const FlatPoint &f2){
  return std::max(f1.getX(), f1.getY()) < std::max(f2.getX(), f2.getY());
}