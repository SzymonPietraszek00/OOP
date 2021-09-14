#pragma once
#include <iostream>
#include <utility>
#include <functional>


///szablon elementu klasy
template<typename T>
class Node{

public:

///konstruktory
  Node(){}
  Node(T value):_value(value){}


///metoda drukujaca wartosc elementu klasy
  void print()const{
    std::cout << _value << "\n";
  }

///wartosc
  T _value;
///nastepny element
  Node *_next = nullptr;  

};

///przeciazony operator sluzacy wypisywaniu wartosci elementu
template<typename T>
std::ostream& operator<<(std::ostream& strm,const Node<T> &temp){

  temp.print();
  return strm;
}

///szablon listy
template<typename T>
class List{

public:

///konstruktor
  List(){}

///konstruktor kopiujacy
  List(const List& temp);

///konstruktor przenoszacy
  List(List&& temp): _head(std::exchange(temp._head,nullptr)),_tail(std::exchange(temp._tail,nullptr)){}

///destruktor
  ~List();

///metoda dodajaca element do listy
  List& add(T val);

///metoda drukujaca
  void print()const;

///metoda sprawdzajaca czy w liscie znajduje sie dana wartosc
  bool contains(T val)const;

///metoda sprawdzajaca czy dla jakiegos argumentu funkcja func zwraca true
  bool contains(std::function<bool(T)>func)const;


///metoda zwracajaca wartosc ostatniego elementu listy i usuwajaca go
  T pop();


private:
///wskaznik na pierwszy element
  Node<T> *_head = nullptr;
///wskaznik na ostatni element
  Node<T> *_tail = nullptr;

};

///przeciazony operator umozliwiajacy wypisanie listy
template<typename T>
std::ostream& operator<<(std::ostream& strm,const List<T> &temp){

  temp.print();
  return strm;
}

template<typename T>
List<T>::List(const List& temp){
  Node<T> *t = temp._head;

  while(t){
    this->add(t->_value);
    t = t->_next;
  }

}

template<typename T>
List<T>::~List(){
     
  Node<T> *t = _head;
  
    while(t != _tail) {

      t = t -> _next;
        
      delete _head;
        
      _head = t;
    }
  
  delete _tail;
  
}

template<typename T>
T List<T>::pop(){

  Node<T> *t = _head;
  Node<T> *temp = _tail;

  while(t){

    if(t->_next == _tail){
      _tail = t;
      _tail->_next = nullptr;
    }

    t = t->_next;
  }
    
  T valu = temp -> _value;
  delete temp;
    
  return valu;

}


template<typename T>
List<T>& List<T>::add(T val){

  Node<T> *temp = new Node<T>(val);

  if(_head==nullptr){
    _head = temp;
    _tail = _head;

  }else{

    _tail->_next = temp;
    _tail = temp;

  }

  return *this;
}

template<typename T>
void List<T>::print()const{
  Node<T> *t = _head;

  if(_head){
    while(t){
      std::cout << t->_value << " ";
      t = t->_next;
    }
  }
}

template<typename T>
bool List<T>::contains(T val)const{
  Node<T> *t = _head;
  while(t){

    if(t->_value == val) return true;
 
    t = t->_next;
  }

  return false;
}

template<typename T>
bool List<T>::contains(std::function<bool(T)>func)const{

  Node<T> *t = _head;
  while(t){

    if(func(t->_value)){
      
      return true;
    }
    t = t->_next;
  }

  return false;

}