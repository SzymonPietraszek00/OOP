#pragma once
#include <cmath>
#include "Argumenty.h"


Argumenty minimum(const Argumenty& a){
  double min = a[0];
	for(int i = 0; i < a.getSize(); i++) {
		if(a[i] < min)
			min = a[i];
	}
	return Argumenty(1)(0,min);

}


Argumenty sum(const Argumenty& a){
  
  	double sum = 0;
	for(int i = 0; i < a.getSize(); i++) {
		sum += a[i];
	}
	return Argumenty(1)(0,sum);
}



Argumenty sq(const Argumenty& a){
  if(a.getSize() != 1) {
		std::cout << "Size error for square root algorithm" << std::endl;
		exit(-1);
	}
	return Argumenty(1)(0,sqrt(a[0]));
}