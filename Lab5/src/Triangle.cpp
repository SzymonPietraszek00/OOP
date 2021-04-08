#include "Triangle.h"


Triangle::Triangle(std::string name): FlatShape(name){
  std::cout << "Mowiac scisle, jestem trojkatem." << std::endl;
}


double Triangle::pole(){
  return (giveout(0).distance(giveout(1)) * giveout(1).distance(giveout(2))) / 2;

}