#include <iostream>
#include <algorithm>

class Target{

public:
  virtual ~Target() = default;

  virtual std::string Request() const{
    return "Target: I am the target";
  }

};

class UsefulThing{

public:
  std::string UsefulRequest()const{
    return "!olleH";
  }

};

class Adapter : public Target{

public:

  Adapter(UsefulThing *thing): _thing(thing){}

  std::string Request() const override{

    std::string reverse_txt = _thing->UsefulRequest();
    std::reverse(reverse_txt.begin(), reverse_txt.end());

    return "Adapter: " + reverse_txt;
  }


private:
  UsefulThing *_thing;

};

void Client(const Target *t){
  
  std::cout << t->Request() << "\n\n";
}

int main(){

  std::cout << "Client: I can work only with the Target objects:\n";
  Target *target = new Target;
  Client(target);
  
  UsefulThing *usefulThing = new UsefulThing;

  std::cout << "Client: The usefulThing class has a weird interface. See, I don't understand it:\n";
  std::cout << "UsefulThing: " << usefulThing->UsefulRequest() << "\n";
 
  std::cout << "\nClient: But I can work with it via the Adapter:\n";

  Adapter *adapter = new Adapter(usefulThing);
  Client(adapter);
  

  delete target;
  delete usefulThing;
  delete adapter;

  return 0;
  
}