#pragma once
#include <iostream>
#include <vector>

///klasa abstrakcyjna opakowujaca daną
class StandardVariable{

public:

//metoda wirtualna wypisuajca
  virtual void Print()const = 0;
};


///szablon klasy reprezentujacy zmienna o zadanym typie
template<typename T>
class Variable : public StandardVariable{

public:

///konstruktor ustawaiajcy nazwę zmiennej oraz wartość odpowiedniego typu
  Variable(std::string name, T value): _name(name), _value(value){}

///metoda drukująca nazwe oraz wartośc zmiennej
  void Print()const override{
    std::cout << _name << ": " << _value << std::endl;
  }

///metoda ustawiając wartość zmiennej
  void SetValue(T value){ _value = value; }

///getter do wartosci zmiennej
  T getValue()const{ return _value; }

///getter do nazwy zmiennej
  std::string getName()const { return _name; }

private:
///nazwa zmiennej
  std::string _name;
///wartosc zmiennej o zadanym typie
  T _value;

};

// template <typename T>
// inline void Variable<T>::Print()const {
//   std::cout << _name << ": " << _value << std::endl;
// }


///alias do zmiennej typu double opakowanej przez szablon klasy
typedef Variable<double> VariableDouble;
///alias do zmiennej typu float opakowanej przez szablon klasy
typedef Variable<float> VariableFloat;
///alias do zmiennej typu int opakowanej przez szablon klasy
typedef Variable<int> VariableInt;
///alias do zmiennej typu char opakowanej przez szablon klasy
typedef Variable<char> VariableChar;
///alias do zmiennej typu bool opakowanej przez szablon klasy
typedef Variable<bool> VariableBool;


///klasa reprezentujaca tablice zmiennych
class ArrayOfVariables{

public:

///konstruktor
  ArrayOfVariables(int size): _size(size){

    /// ZAKOMENTOWANA PROBA ZREALIZOWANIA ZADANIA NA ZWYKLEJ TABLICY
    // _arr = new StandardVariable[size];
    // for(int i = 0; i < _size; i++){
    //   _arr[i] = nullptr;
    // }

  }

///metoda wypisujaca zawartosc tablicy zmiennych
  void Print()const{

    /// ZAKOMENTOWANA PROBA ZREALIZOWANIA ZADANIA NA ZWYKLEJ TABLICY
    // for(int i = 0; i < _size; i ++){
    //   _arr[i]->Print();
    // }


    for(auto x: _arr){
      x->Print();
    }

  }

///szablon metody twrozacej zmienna, dodającej zmienną do tablicy i zwracający obiekt-zmienna
  template<typename T>
  Variable<T> * CreateAndAdd(std::string name, T value){

    Variable<T> * element = new Variable<T>(name,value);

    /// ZAKOMENTOWANA PROBA ZREALIZOWANIA ZADANIA NA ZWYKLEJ TABLICY
    // for(int i = 0 ; i < _size; i++){
    //   if(_arr[i] == nullptr){
    //     _arr[i] = element;
    //     return element;
    //   }
    // }

    _arr.push_back(element);
    return element;
  }


private:

///rozmiar tablicy niestety nieprzydatny w moim rozwiazniu zadania na std::vector :(
  int _size;

///kontener na zmienne
  std::vector<StandardVariable*> _arr;

  /// ZAKOMENTOWANA PROBA ZREALIZOWANIA ZADANIA NA ZWYKLEJ TABLICY
  // StandardVariable *_arr;
 

};


///szablon klasy - zmienne z jednostką 
template<typename T>
class VariableWithUnits : public Variable<T>{

public:
///konstruktor
  VariableWithUnits(std::string name, T value, std::string jednostki): Variable<T>(name,value), _jednostki(jednostki){}

///metoda drukujaca zmienna wraz z jednostka
  void Print()const{

    std::cout << Variable<T>::getName() << ": " << Variable<T>::getValue();

    std::cout << " [" << _jednostki << "]" << std::endl;
  }

private:
///jednostka zmiennej
  std::string _jednostki;

};