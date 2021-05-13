#include "Table.h"


void Table::operator+=(Product p){ 
  
  _table.push_back(p); 

  if(p.getVal().size() < minRow){
    minRow = p.getVal().size();
  } 
}


void Table::print()const{
    
  std::for_each(_table.begin(), _table.end(), [](Product p){
    p.print();
  });

  std::cout << std::endl;
}


Table& Table::sort(float x){

  if( (x+1) > minRow ){

    std::cout << "Indeks " << x << " nieprawidlowy!" << std::endl;
  }else{

    std::sort(_table.begin(), _table.end(), [x](Product &p1, Product &p2){

      return p1.getVal()[x] < p2.getVal()[x];

    });

  }

  return *this;
}


Table& Table::sortBy(bool (&func)(const Product& p1, const Product& p2)){

  std::sort(_table.begin(), _table.end(), func);  
  return *this;
}