#include "Animals.h"


void Sheep::print()const{

  std::cout << "- Owca " << getName();

  if(_flag){
    std::cout << " ostrzyzona";
  }else{
    std::cout << " nieostrzyzona";
  }

}

Sheep::~Sheep(){
  
    std::cout << "Owca " << getName();
    
    if(_flag){
      std::cout << " ostrzyzona"; 
    }else{
      std::cout << " nieostrzyzona"; 
    }
    
    std::cout << " wraca do zagrody\n";
}

void Cow::print()const{
  std::cout << "- Krowa " << getName();
}

void Horse::print()const{
  std::cout << "- Kon " << getName();
}
