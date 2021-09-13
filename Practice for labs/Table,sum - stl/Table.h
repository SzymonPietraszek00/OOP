#pragma once
#include <iostream>
#include "Data.h"

class Table{

public:

  unsigned int minRow = 150;

  void operator+=(const Data &d){
    _arr.push_back(d);
    if(minRow > d.getVal().size()){
      minRow = d.getVal().size();
    }
  }

  void print()const{

    std::for_each(_arr.begin(), _arr.end(), [](Data x){
      x.print();

    });
  }

  Table& sort(unsigned x){

    if(minRow <= x)
    {
      std::cout<<"Indeks 3 nieprawidlowy!"<<std::endl;
     
    }
    else{
      std::sort(_arr.begin(), _arr.end(), [x](const Data &d, const Data &d2){

        return d.getVal()[x] < d2.getVal()[x];


      });
    }

     return *this;
    
  }

  const Table& sortBy(bool func(const Data&, const Data& )){

    

    std::sort(_arr.begin(), _arr.end(), func);

    return *this;
  }


private:
  std::vector<Data> _arr; 

};