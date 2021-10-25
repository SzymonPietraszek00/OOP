#include <iostream>
#include "Car.h"
#include "CarFactory.h"


void ClientCode(const CarFactory& carFactory) {

  std::cout << "Client: I'm not aware how factory works, but I need a car\n";
  carFactory.SomeOperation();

  std::cout << '\n';

}

int main() {

  std::cout << "Now AudiFactory will work.\n";
  
  CarFactory* carFactory = new AudiFactory();
  ClientCode(*carFactory);
  std::cout << std::endl;


  std::cout << "Now MercedesFactory will work.\n";
  CarFactory* carFactory2 = new MercedesFactory();
  ClientCode(*carFactory2);

  delete carFactory;
  delete carFactory2;
  
  return 0;
}