#include <iostream>
#include "CarFactory.h"
#include "Car.h"

void ClientCode(const CarFactory &factory) {
  const NewCar * newcar = factory.CreateNewCar();
  const OldCar * oldcar = factory.CreateOldCar();
  std::cout << oldcar->doSomethingOld() << "\n";
  std::cout << oldcar->AnotherUsefulFunctionOld(*newcar) << "\n";
  delete newcar;
  delete oldcar;
}

int main() {
  
  std::cout << "Client: Testing client code with the Audi factory type: ";
  AudiCarFactory *f1 = new AudiCarFactory();
  ClientCode(*f1);
  std::cout << std::endl;
  delete f1;

  
  std::cout << "Client: Testing the same client code with the Mercedes factory type: ";
  MercedesCarFactory *f2 = new MercedesCarFactory();
  ClientCode(*f2);
  delete f2;
  
  return 0;
}