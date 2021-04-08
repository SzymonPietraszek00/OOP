#include "FlatShape.h"



FlatShape::FlatShape(std::string name): _name(name){
  std::cout << "Jestem nowa figura " << _name << std::endl;
}


FlatShape& FlatShape::dodajW(const Vertex &v){

  _arr.push_back(v);

  return *this;
}


FlatShape& FlatShape::operator+=(const Vertex &v){

  _arr.push_back(v);
  return *this;
}


bool FlatShape::operator==(FlatShape& f){

  if(this == &f) return 1;

  if(_arr.size() != f._arr.size()) return 0;

  for(unsigned i = 0; i < _arr.size(); i++)
    if(_arr[i] != f._arr[i]) return 0;



  return 1;

}


std::ostream& operator<<(std::ostream& strm, FlatShape &f){

  std::cout << "Figura: " << f.nazwa() <<  std::endl;

  for(unsigned i = 0; i < f.size(); i++){
    strm << f[i];
  }

  return strm << std::endl;
}