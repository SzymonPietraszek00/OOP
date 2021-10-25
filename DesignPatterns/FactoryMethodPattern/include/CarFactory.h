#pragma once
#include <iostream>
#include "Car.h"

class CarFactory{

public:
  virtual ~CarFactory(){}

  virtual Car* FactoryMethod() const = 0;

  void SomeOperation() const {

    
    Car* car = this->FactoryMethod();
    
    std::cout << "CarFactory: The same factory code has just worked with ";
    
    car->doSomething();

    delete car;
  
  }

private:


};


class AudiFactory : public CarFactory{

public:

  Car* FactoryMethod()const override{

    return new Audi();
  }

};


class MercedesFactory : public CarFactory{

public:

  Car* FactoryMethod()const override{

    return new Mercedes();
  }

};


