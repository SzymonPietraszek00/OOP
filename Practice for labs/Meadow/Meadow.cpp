#include "Meadow.h"



void Meadow::print(std::string txt){
  std::cout << "=== " << txt << " ===" << std::endl;

  std::for_each(_arr.begin(), _arr.end(), [](auto &x){

    if(x!=nullptr){
      x->print();
      std::cout << std::endl;
    }

  });

}


void Meadow::countNames(){

  std::list<std::string> names;

  for(auto &x: _arr){

    if(x!=nullptr)
      names.push_back(x->getName());
  }

  std::set<std::string> keys(names.begin(), names.end());

  for (auto& key : keys)
		std::cout << key << ": " << std::count(names.begin(), names.end(), key) << std::endl;

}


std::list<Sheep*> Meadow::getSheepHerd(){

  std::list<Sheep*> shep;

  for(auto &x : _arr){
    if(dynamic_cast<Sheep*>(x.get())){
      shep.push_back(dynamic_cast<Sheep*>(x.get()));
    }

  }
  return shep;
}


