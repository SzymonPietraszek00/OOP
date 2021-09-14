#include "Argumenty.h"

std::ostream& operator<<(std::ostream& str, const Argumenty& a) {
	for(int i = 0; i < a._size; i++) {
		str << a[i] << " ";
	}
	return str;
}

Argumenty::Argumenty(const Argumenty& a1){
  _size = a1._size;
    
   for(unsigned i = 0; i< a1._arr.size(); i++){
    _arr.push_back(a1._arr[i]);
  }

}

void Argumenty::print(std::string nm, std::ostream& strm) const{

  strm << nm << " " ;

  for(int i = 0; i< _size; i++){
    strm << _arr[i] <<" ";
  }
  strm << std::endl;
}



Argumenty& Argumenty::operator=(const Argumenty& other) {
	
  if(_arr == other._arr) {
		return *this;
	}

  _size = other.getSize();
	
  for(int i = 0; i < _size; i++) {
		_arr[i] = other._arr[i];
	}
	return *this;
}