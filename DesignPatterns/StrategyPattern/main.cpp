#include <iostream>



class Strategy{

public:
  virtual ~Strategy(){}
  virtual std::string DoStrategy() const = 0;

};

class StockMarket{

public:
  StockMarket(Strategy *strategy): _strategy(strategy){}

  ~StockMarket(){ delete _strategy; }

  void setStrategy(Strategy *strategy){
    delete _strategy;
    _strategy = strategy;
  }

  void DoLogic()const{
    std::cout << "DoLogic: " << _strategy->DoStrategy() << std::endl;
  }

private:

  Strategy *_strategy;

};

class InvestingStrategyA : public Strategy{

public:
  std::string DoStrategy() const override{
    return "InvestingStrategyA: You LOSE all money!\n";
  }

};



class InvestingStrategyB : public Strategy{

public:
  std::string DoStrategy() const override{
    return "InvestingStrategyB: You EARN 200% of your invested money!\n";
  }

};

int main(){

  StockMarket *stockMarket = new StockMarket(new InvestingStrategyA);

  stockMarket->DoLogic();

  stockMarket->setStrategy(new InvestingStrategyB);
  stockMarket->DoLogic();

  delete stockMarket;

}