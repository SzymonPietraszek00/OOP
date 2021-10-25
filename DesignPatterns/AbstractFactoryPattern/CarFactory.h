#pragma once
#include <iostream>
#include "Car.h"


class CarFactory {
 public:
  virtual ~CarFactory(){}
  virtual NewCar *CreateNewCar() const = 0;
  virtual OldCar *CreateOldCar() const = 0;
};

class AudiCarFactory : public CarFactory {
 public:

  ~AudiCarFactory(){}
  NewCar *CreateNewCar() const override {
    return new NewAudi();
  }
  OldCar *CreateOldCar() const override {
    return new OldAudi();
  }
};


class MercedesCarFactory : public CarFactory {
 public:
  ~MercedesCarFactory(){}
  NewCar *CreateNewCar() const override {
    return new NewMercedes();
  }
  OldCar *CreateOldCar() const override {
    return new OldMercedes();
  }
};