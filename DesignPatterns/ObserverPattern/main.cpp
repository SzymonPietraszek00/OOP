#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

class Observer{

public:
  virtual void update(unsigned) = 0;
};


class Product{

public:
  virtual void add(Observer *o) = 0;
  virtual void remove(Observer *o) = 0;
  virtual void notify() = 0;
};


class PromotedProduct : public Product{

public:

  void add(Observer *o) override{
    _observers.push_back(o);
  }

  void remove(Observer *o) override{

    auto obs = std::find(_observers.begin(), _observers.end(), o);

    if (obs != _observers.end()) { 
      _observers.erase(obs); 
    }

  }

  void notify() override{

     std::cout << "\nPROMOTED PRODUCT: HI CLIENTS, THERE IS A NEW DISCOUNT AVAILABLE\n" << std::endl;
    
    for(auto a : _observers){
      a->update(_discountRate);
    }
  }

  void setPromotion(unsigned value){
    _discountRate = value;

   
    notify();
  }

  unsigned getDiscount()const { return _discountRate; }


private:
  unsigned _discountRate;
  std::vector<Observer *> _observers;

};


class Client : public Observer{

public: 

  Client(unsigned id): _id(id){}

  void update(unsigned discount) override{

    _discount = discount;
    std::cout << "CLIENT " << _id << ": I have " << _discount << " percent discount on product that I want\n";
  }

private:
  unsigned _id;
  unsigned _discount = 0;

};

class PremiumClient : public Observer{

public: 

  PremiumClient(unsigned id): _id(id){}

  void update(unsigned discount) override{

    _discount = 2*discount;
    std::cout << "PREMIUM CLIENT " << _id << ": I have " << _discount << " percent discount on product that I want\n";
  }

private:
  unsigned _id;
  unsigned _discount = 0;

};




int main() {
  
  PromotedProduct promotedProduct;

  Client first(1);
  Client second(2);
  PremiumClient fifth(5);

  promotedProduct.add(&first);
  promotedProduct.add(&second);
  promotedProduct.add(&fifth);

  promotedProduct.setPromotion(15);

  promotedProduct.remove(&first);

  promotedProduct.setPromotion(20);

}