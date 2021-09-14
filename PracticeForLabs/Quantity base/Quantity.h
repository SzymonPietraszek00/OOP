#pragma once
#include <iostream>


class QuantityBase{

public:
  QuantityBase(std::string name):_name(name){}
  virtual void Print()const = 0 ;
  virtual ~QuantityBase(){}

protected:

  std::string _name;

};


template<typename T>
class Quantity : public QuantityBase{

public:

  Quantity(std::string name, T value): QuantityBase(name), _value(value){}

  void Print()const{
    std::cout << _name << " " << _value << std::endl;
  }

  void SetValue(T value){ _value = value;}

protected:
  T _value;

};

using QuantityDouble = Quantity<double>;
using QuantityFloat = Quantity<float>;
using QuantityInt = Quantity<int>;
using QuantityChar = Quantity<char>;
using QuantityBool = Quantity<bool>;

template<typename T>
class QuantityWithUnits : public Quantity<T>{

public:
  QuantityWithUnits(std::string name, T value, std::string id): Quantity<T>(name,value), _id(id){}

  void Print()const{
    std::cout << Quantity<T>::_name << " " << Quantity<T>::_value << " " << _id << std::endl;
  }


private:
  std::string _id;

};



class ArrayOfQuantities{


public:

  ArrayOfQuantities(int x){
    _size = x;
    _counter = 0;
    _arr = new QuantityBase*[x];

  
  }

  ~ArrayOfQuantities(){
    for(int i = 0 ; i < _counter; i++){
      delete _arr[i];
    }

    delete [] _arr;
  }

  template<typename T>
  Quantity<T>* CreateAndAdd(std::string name, T value){

    Quantity<T>* temp = new Quantity<T>(name,value);
    _arr[_counter++] = temp;
    return temp;
  }
  
  void Print()const{

    for(int i = 0; i < _counter; i++){
      _arr[i]->Print();
    }
  }

private:
  int _size;
  int _counter;
  QuantityBase **_arr;


};

