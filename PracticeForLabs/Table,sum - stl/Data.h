#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

class Data{

public:
  Data(std::string day, std::vector<double> val): _day(day), _val(val){}

  void print()const{

    std::cout << _day << " : ";
    std::for_each(_val.begin(), _val.end(), [](double val){

      std::cout << std::setw(6) << val;
    });
    std::cout << std::endl;
  }

  const std::vector<double>& getVal()const { return _val; }

private:
  std::string _day;
  std::vector<double> _val;

};