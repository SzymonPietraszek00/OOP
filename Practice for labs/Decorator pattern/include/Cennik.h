#pragma once
#include <iostream>
#include <cmath>


class Towar{

public:

  virtual std::string nazwa() const = 0;
  virtual  double cena() const = 0;
  virtual ~Towar() = default;
protected:
  Towar *_product;

};

class Zaokraglenie: public Towar{
  
public:
  Zaokraglenie(Towar *t){_product = t;}
   std::string nazwa() const{return _product->nazwa() + " Zaokraglone w gore ";}
   double cena() const{return std::ceil(_product->cena()) - 0.01;}

};


class OplataStala: public Towar{ 

public:
  OplataStala(Towar* t,double x): _oplatastala(x){_product = t;}
  std::string nazwa() const{return _product->nazwa()+ "+Oplata Stala: " +std::to_string(_oplatastala) + " ";}
   double cena() const{return _product->cena()+_oplatastala;}
private:
  double _oplatastala = 0;

};


class Marza: public Towar{

public:

   Marza(Towar* t,double x): _marza(x){_product = t;}
   std::string nazwa() const{ return _product->nazwa()+ "*Marza: " +std::to_string(_marza*100) + "% ";}
   double cena() const{return _product->cena()+_product->cena()*_marza;}
private:
  double _marza = 0;

};

class Promocja: public Towar{ 

public:
  Promocja(Towar* t,double x): _promocja(x){ _product = t;}
  std::string nazwa() const{return _product->nazwa() + "   Na promocji: " + std::to_string(_promocja*100) + "% "; }
   double cena() const{return (1-_promocja)*_product->cena();}

private:
  double _promocja = 0;

};