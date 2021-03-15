#include "MathV.h"


MathV::MathV(unsigned int size): _size(size), _arr(new int[size]){
   for(unsigned int i = 0; i < size; i++){
     _arr[i] = 0;
   } 
}

MathV::~MathV(){
  delete [] _arr;
  _arr = nullptr;
}

MathV::MathV(const MathV& v): _size(v._size),_arr(new int[v._size]){

  for(unsigned int i = 0; i < _size; i++){
     _arr[i] = v._arr[i];
   } 
  
}




void MathV::print(std::string name)const{
  std::cout << name << "[";

  for(unsigned int i = 0; i < _size-1; i++){
     std::cout << _arr[i] << ", ";
   } 

   std::cout << _arr[_size-1] << "]" << std::endl;
}



double MathV::dot(MathV v1,MathV v2){

  if(v1._size != v2._size){
    std::cout << "Error, vectors of different dimensions!" << std::endl;
    return 0;
  }

  double d = 0;

  for(unsigned int i = 0; i < v1._size; i++){
     d += v1._arr[i] * v2._arr[i];
   } 

  return d;
  
}


MathV operator+=(const MathV& v1, const MathV& v2){

  for(unsigned int i = 0; i < v1._size; i++){
    v1._arr[i] += v2._arr[i];
  } 

  return v1;
}


MathV operator+=(const MathV& v1, int x){

  for(unsigned int i = 0; i < v1._size; i++){
    v1._arr[i] += x;
  } 
  
  return v1;
}