#pragma once
#include <iostream>



#include "Functions.h"


class SecureCalc{

public:

  static void run(const Functions &f, double val){

   try{
     f.calc(val);
   }catch(std::domain_error er){
     std::cout<< "->Error " << er.what() << " \n";
   }
  }

};