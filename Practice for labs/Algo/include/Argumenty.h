#pragma once
#include <iostream>

class Argumenty{

public:
  Argumenty(int size):_size(size),_arr(new float[size]){
    for(int i = 0; i < size; i++){
      _arr[i] = 0.0;

    }
  }

  ~Argumenty(){delete [] _arr;}

  Argumenty& operator()(int index, float value){
    _arr[index] = value;
    return *this;
  }

  void print(std::string nm, std::ostream& strm = std::cout) const{

    strm << nm << " " ;

    for(int i = 0; i<_size; i++){
      strm << _arr[i] <<" ";
    }
    strm << std::endl;
  }

  int getSize()const{return _size;}

  auto& getArr()const {return _arr;}

private:
  int _size;
  float *_arr;
  

};

