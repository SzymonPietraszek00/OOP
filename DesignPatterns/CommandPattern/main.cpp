#include <iostream>


///command interface
class Command{

public:
  virtual ~Command(){}
  virtual void execute() const = 0;

};


///receiver
class MyBank{

public:
  MyBank(int balance = 0): _balance(balance) {}

  void deposite(unsigned cash){ 
    std::cout << "MyBank: I am depositing " << cash << "\n";
  
    _balance += cash;

    std::cout << "MyBank: Your balance is " << _balance << " now\n";
  }

  void withdraw(unsigned cash){ 
    std::cout << "MyBank: I am withdrawing " << cash << "\n";
  
    _balance -= cash;

    std::cout << "MyBank: Your balance is " << _balance << " now\n";
  
  }

private:
  
  int _balance;
};


class HelloCommand : public Command{

public:

  void execute() const override{
    std::cout << "Hello in MyBank!!" << std::endl;
  }

};


class WithdrawCommand : public Command{

public:

  WithdrawCommand(MyBank *bank, unsigned cash): _bank(bank), _cash(cash){}


  void execute() const override{
    std::cout << "WithdrawCommand: MyBank please withdraw cash\n";

    _bank->withdraw(_cash);
  }

private:
  MyBank *_bank;
  unsigned _cash;
  
};


class DepositeCommand : public Command{

public:

  DepositeCommand(MyBank *bank, unsigned cash): _bank(bank), _cash(cash){}

  void execute() const override{
    std::cout << "DepositeCommand: MyBank please deposite cash\n";

    _bank->deposite(_cash);
  }

private:
  MyBank *_bank;
  unsigned _cash;
  
};


class Invoker{

public:

  // ~Invoker(){
  //   delete _command;
  // }

  void setCommand(Command *command){

    _command = command;
  }

  void DoSomething(){
    std::cout << "\nInvoker: Let's do something\n";

    if(this->_command){
      _command -> execute();
    }

  }

private:
  Command *_command;

};


int main() {

  MyBank *myBank = new MyBank;
  Invoker *invoker = new Invoker;

  HelloCommand *helloCommand{};
  DepositeCommand *depositeCommand = new DepositeCommand(myBank, 3500);
  WithdrawCommand *withdrawCommand = new WithdrawCommand(myBank, 1500);

  invoker->setCommand(helloCommand);
  invoker->DoSomething();
  
  invoker->setCommand(depositeCommand);
  invoker->DoSomething();

  invoker->setCommand(withdrawCommand);
  invoker->DoSomething();
 
  delete myBank;
  delete invoker;
  delete helloCommand;
  delete withdrawCommand;
  delete depositeCommand;
  
  
}