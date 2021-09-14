#pragma once
#include <iostream>
#include <cmath>
#include <stdexcept>


class Functions{
public:
  virtual void calc(double val)const = 0;

  

};


class Log10 : public Functions{
public:
  void calc(double val)const override{
    std::cout << "Obliczamy: log10(" << val << ")\n";

    if(val<0){
      throw std::domain_error("wrong argument of log10");
    }else{

      std::cout << "->Wynik: " << std::log10(val) << std::endl;
    }
  }


};


class Asin : public Functions{
public:

  void calc(double val)const override{
    std::cout << "Obliczamy: arcsin("<< val <<")\n";

    if(val<=1){
      std::cout << "->Wynik: " << std::asin(val) << std::endl; 
    }else{
      throw std::domain_error("wrong argument of arcsin");
    }
  }

};


class DivideBy : public Functions{
public:
  DivideBy(double v):_v(v){}
  void calc(double val)const override{

    std::cout << "Obliczamy: DivideBy(" << val << ")\n";
    
    if(val==0){
      throw std::domain_error("divide by zero!");
    }else{

      std::cout << "->Wynik: " << _v/val << std::endl;
    }
  }

private: 
  double _v;

};