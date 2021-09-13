#pragma once
#include <iostream>


class Prostokat : public Figura{

public:
  Prostokat(std::string name): Figura(name){
    std::cout << "Tak naprawdę jestem prostokątem." << std::endl;
  }

 
};