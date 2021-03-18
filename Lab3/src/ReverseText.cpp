#include "../include/ReverseText.h"


ReverseText::ReverseText(const char* txt){

  _len = strlen(txt);
  _txt = new char[_len+1];
  strcpy(_txt,txt);
}


ReverseText::~ReverseText(){
  delete [] _txt;

  _next = nullptr;
  
}


void ReverseText::operator-=(const char *txt){

  
  ReverseText *temp = this;

  while(temp->_next){
    temp = temp->_next;
  }

  temp->_next = new ReverseText(txt);
}




void ReverseText::operator=(ReverseText&& r){

    delete [] _txt;

    _len = r._len;
    _txt = r._txt;
    _next = r._next;

    r._len = 0;
    r._txt = nullptr;
    r._next = nullptr;
}



std::ostream& operator<<(std::ostream& strm, const ReverseText &r){

  if(r._txt == nullptr) return strm;

  const ReverseText *temp = &r;

  int x = r.fragments();

  while(x>0){

    temp = &r;
    
    for(int i = 0; i<x-1; i++){
      temp = temp->_next;
    }

    x--;
    strm << temp->_txt;
  }

  return strm;
}


int ReverseText::fragments()const{ 

    int _words = 0;
    const ReverseText *temp = this;

    while(temp->_next){
      temp = temp->_next;
      _words++;
    }

    _words++;
    
    return _words;
    
}

int ReverseText::size()const{

  int sum = 0;

  const ReverseText *temp = this;

  while(temp->_next){
    
    sum += temp->_len;
    temp = temp->_next;
    
  }
  sum += temp->_len;
  return sum;
}


const ReverseText ReverseText::fragment(unsigned int x)const{

    const ReverseText *temp = this;
    for(unsigned int i = 0; i < x; i ++) temp = temp->_next;
    
    return *temp;

}