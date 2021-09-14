#pragma once
#include <iostream>
#include "Animals.h"
#include <list>
#include <memory>
#include <algorithm>
#include <set>



class Meadow{

public:


  void add(std::unique_ptr<Animal> x){ _arr.push_back(std::move(x)); }

  void print(std::string txt);

  void countNames();

  std::list<Sheep*> getSheepHerd();



private:
  std::list<std::unique_ptr<Animal>> _arr;

};