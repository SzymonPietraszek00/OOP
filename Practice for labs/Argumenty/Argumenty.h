#pragma once
#include <iostream>
#include <vector>

class Argumenty{
 
friend std::ostream& operator<<(std::ostream& str, const Argumenty& a);
 
public:
  Argumenty(int size):_size(size){
    for(int i = 0; i < size; i++){
      _arr.push_back(0.0);
    }
  }


  Argumenty(const Argumenty& a1);

  Argumenty& operator()(int index, float value){
    _arr.at(index) = value;
    return *this;
  }

  void print(std::string nm, std::ostream& strm = std::cout) const;

  float operator[](unsigned x)const {return _arr[x];}

  static Argumenty pojedynczy(float x){
    
    return Argumenty(1)(0,x);
  }


  Argumenty& operator=(const Argumenty& other);

  
int getSize() const {
	return _size;
}

private:
  int _size;
  std::vector<float>_arr;
  

};
