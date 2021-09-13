#pragma once
#include <iostream>
#include "Animal.h"
#include <list>


class Sheep : public Animal{

public:

  Sheep(std::string name) : Animal(name){}

  void print()const override;

  ~Sheep();
  

  void shear(){
    _flag = true;
  }

private:
  bool _flag = false;
};


class Cow : public Animal{

public:

  Cow(std::string name) : Animal(name){}

  ~Cow(){ std::cout << "Krowa "<< getName() << " wraca do obory\n"; }

  void print()const override;

};



class Horse : public Animal{

public:

  Horse(std::string name) : Animal(name){}

  ~Horse(){ std::cout << "Kon " << getName() << " wraca do stajni\n"; }

  void print()const override;

};