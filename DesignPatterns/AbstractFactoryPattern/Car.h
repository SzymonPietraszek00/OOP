#pragma once
#include <iostream>



class NewCar{

public:
  virtual ~NewCar(){}
  virtual std::string doSomethingNew() const = 0;

};


class NewAudi : public NewCar{

public:
  std::string doSomethingNew() const override{
    return "NewAudi";  
  }

};


class NewMercedes : public NewCar{

public:
  std::string doSomethingNew()const  override{
    return "NewMercedes";  
  }

};


class OldCar{

public:
  virtual ~OldCar(){}
  virtual std::string doSomethingOld() const = 0;
  virtual std::string AnotherUsefulFunctionOld(const NewCar &collaborator) const = 0;

};


class OldAudi : public OldCar{

public:
  std::string doSomethingOld() const override{
    return "OldAudi";
 
  }

  std::string AnotherUsefulFunctionOld(const NewCar &collaborator) const override {
    const std::string result = collaborator.doSomethingNew();
    return "The result of the OldAudi collaborating with ( " + result + " )";
  }

};


class OldMercedes : public OldCar{

public:
  std::string doSomethingOld() const override{
    return "OldMercedes";  
  }

  std::string AnotherUsefulFunctionOld(const NewCar &collaborator) const override {
    const std::string result = collaborator.doSomethingNew();
    return "The result of the OldMercedes collaborating with ( " + result + " )";
  }

};
