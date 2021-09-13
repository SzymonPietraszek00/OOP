#pragma once
#include <iostream>
#include <cmath>


class Point2D{

public:
  Point2D(int x = 0, int y = 0): _x(x), _y(y), _d(sqrt(pow(x,2)+pow(y,2))){}

  bool operator<(const Point2D& d)const{
    return _d < d._d;
  }

  int getX()const{ return _x; }
  int getY()const{ return _y; }
  float getD()const { return _d; }


  void Print()const{
    std::cout << "Point coordinates (" << getX() << ", " << getY() << ") distance from origin: " << getD() << std::endl;
   
  }

 
  static void FunctionPrintY(const Point2D& p){
    std::cout << "Function print y=" << p.getY() << std::endl;
  }

  static void PrintPoint(const Point2D point){
    point.Print();
  }

private:
  int _x, _y;
  float _d;

};

class OrderAscX{

public:
  bool operator()(const Point2D &d1, const Point2D &d2){
    return d1.getX() < d2.getX();
  }

};


class OrderDescY{

public:
  bool operator()(const Point2D &d1, const Point2D &d2){
    return d1.getY() < d2.getY();
  }

};

inline bool MaxDistanceAsc(const Point2D& d1, const Point2D& d2){
  
  return std::max(d1.getX() , d1.getY()) < std::max(d2.getX() , d2.getY());
  
}

inline void FunctionPrintX(const Point2D& p){
  std::cout << "Function print x=" << p.getX() << std::endl;
}