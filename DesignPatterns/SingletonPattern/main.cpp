#include <iostream>


class Singleton{

public:

  static Singleton* getInstance();

  Singleton(Singleton &s) = delete;
  void operator=(Singleton &s)  = delete;

private:
  Singleton(){}
  ~Singleton(){}

  Singleton(const Singleton&);
  Singleton& operator=(const Singleton&);

};



Singleton* Singleton::getInstance(){
  
  static Singleton _singleton;

  return &_singleton;
}

int main() {
  
  Singleton *first = Singleton::getInstance();
  Singleton *second = Singleton::getInstance();


  std::cout << first << "\n";
  std::cout << second << "\n";
}