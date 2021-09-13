#pragma once
#include <iostream>


class PredkoscMaksymalna{

  friend std::ostream& operator<<(std::ostream& strm, const PredkoscMaksymalna &pr);

public:
  PredkoscMaksymalna(int pr = 0): _pr(pr){}

  ~PredkoscMaksymalna() = default;

  int Peer()const { return _pr; }

private:
  int _pr;
};


std::ostream& operator<<(std::ostream& strm, const PredkoscMaksymalna &pr){


  return strm << pr._pr << "km/h";
}