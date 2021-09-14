#pragma once
#include <iostream>
#include "Car.h"

class Factory{

public:

  template<typename T>
  void prototype(const T &val){
    manufacture<T>(&val);
  }

  template<typename T>
  T &manufacture(const T *value = nullptr){
    static T temp;
    if(value){
      temp = *value;
    }else{
      if(!temp)
        std::cout << "No prototype for this type: ";
    }
    return temp;
  }



private:
  int _value;

};