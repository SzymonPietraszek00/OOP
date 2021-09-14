#include <iostream>

struct is_printable{
  virtual void print()const = 0;
};

struct A : public is_printable{
  A(std::string name):_name(name){}

  void print()const override{
    std::cout<< _name;
  }

  std::string _name;
};

struct B: public is_printable{
  B(int x):_x(x){}
  void print()const override{
    std::cout<< _x;
  }

  int _x;
};


std::ostream& operator<<(std::ostream& s, const is_printable& o){
  o.print();
  return s;
}

int main(){
  A a{"Tekst"};
  B b{123};
  std::cout << "a:\t" << a << "; b:\t" << b << "\n";
  is_printable& a_r = a;
  is_printable& b_r = b;
  std::cout << "a_r:\t" << a_r << ": b_r\t" << b_r << "\n";
}

// a: Tekst; b:  123
// a_r: Tekst: b_r:  123