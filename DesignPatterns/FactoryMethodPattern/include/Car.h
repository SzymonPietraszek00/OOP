#pragma once
#include <iostream>


class Car{

public:
  virtual ~Car(){}
  virtual void doSomething() = 0;

};


class Audi : public Car{

public:
  void doSomething() override{
    std::cout << "Audi" << '\n';  
  }

};

class Mercedes : public Car{

public:
  void doSomething() override{
    std::cout << "Mercedes" << '\n';  
  }

};
