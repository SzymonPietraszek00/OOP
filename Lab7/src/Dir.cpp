#include "Dir.h"


Dir::~Dir(){
  std::cout << "Deleting Dir: " << getName() << std::endl;
    

  for(auto *l : _link){
    std::cout << "About to delete " << l->getName() << std::endl;
    delete l;
  }

  _link.clear();
}



void Dir::print(const int spaces)const{

  Link::print(spaces);
  std::cout << " (DIR)" << std::endl;

  for(auto *l : _link){

    l->print(spaces+2);
  }
}


Dir* Dir::findDir(std::string name){

  for(auto *l : _link){

    if(dynamic_cast<Dir*>(l)){

      if(l->getName() == name){ 

        return dynamic_cast<Dir*>(l);

      }else{

        return dynamic_cast<Dir*>(l)->findDir(name);
      }

    }
  }

  return this;
}


Link* Dir::get(const std::string name){

  for(auto *l : _link){

    if(l->getName() == name){ 
      return dynamic_cast<Link*>(l);
    }else{
      if(dynamic_cast<Dir*>(l)){

      Link *el = dynamic_cast<Dir*>(l)->get(name);
      if(el != nullptr) return el;

      }
    }
      
  }

  return nullptr;
}