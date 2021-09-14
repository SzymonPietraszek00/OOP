#pragma once
#include <iostream>
#include <vector>

class Obserwator{

public:
 
  virtual void dodajDane(int x) = 0;
protected:
  std::vector<int> _dane;
};


class ObserwatorLicznik : public Obserwator{

public:

  void dodajDane(int x)override{
    _dane.push_back(x);
    
  }

  int suma(){
    
    for(unsigned i = 0; i < _dane.size(); i++) {
      _suma += _dane[i];
    }
    
    return _suma;
    
  }

private:
  int _suma = 0;

};

class ObserwatorWypisywacz : public Obserwator{

public:

  void dodajDane(int x)override{
    _dane.push_back(x);
    std::cout << x << " ";
  }

private:

};