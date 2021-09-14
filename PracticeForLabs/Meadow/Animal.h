#pragma once
#include <iostream>


class Animal{

public:
  Animal(std::string name): _name(name){}

  virtual void print() const = 0;

  std::string getName()const { return _name; }

  virtual ~Animal() = default;

protected:
  std::string _name;

};