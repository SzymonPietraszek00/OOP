#pragma once
#include <iostream>

class Car{
  public:

    Car() = default;
  
    Car(std::string n){
      _n = n;
    }

    void print(){
      std::cout<<"Car: "<<_n<<std::endl;
    }

    operator bool()
    {
        if(this->_n.empty()){
            return false;
        }
        else
            return true;
    }

  private:
    
    std::string _n;
};