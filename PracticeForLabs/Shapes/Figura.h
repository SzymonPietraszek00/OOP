#pragma once
#include <iostream>
#include "Wierzcholek.h"
#include <vector>
#include <cmath>

class Figura{

  friend std::ostream& operator<<(std::ostream& strm, const Figura &f);

public:
  Figura(std::string name): _name(name){ std::cout << "Jestem nową figurą " << _name << std::endl; }

  Figura& operator+=(const Wierzcholek &w){
    _arr.push_back(w);

    return *this;
  }


  Figura& dodajW(const Wierzcholek &w1){
    
    _arr.push_back(w1);

    return *this;
  }


  std::string nazwa()const{
    return _name;
  }

  unsigned pole()const{

    return _arr[0].dist(_arr[1]) * _arr[1].dist(_arr[2]);
  }


  bool operator==(const Figura &f){

    if(this == &f) return 1;

    if(_arr.size() != f._arr.size()) return 0;

    for( unsigned i = 0; i < _arr.size(); i++){
      if(_arr[i] != f._arr[i]) return 0;
    }

    return 1;
  }

  

private:
  std::string _name;

  std::vector<Wierzcholek> _arr;
};


std::ostream& operator<<(std::ostream& strm, const Figura &f){


  strm << "Figura " << f._name << ":" << std::endl;

  for(unsigned i = 0; i < f._arr.size(); i++){
    strm << f._arr[i];
  }

  return strm << std::endl;
}