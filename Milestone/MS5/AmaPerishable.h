// Name:  ANCHETA, Jesus Jr.
// ID: 017 433 152
// Email: JJANCHETA@myseneca.ca
// Filename: AmaPerishable.h
// Milestone: 5


#ifndef SICT_AMAPERISHABLE_H__
#define SICT_AMAPERISHABLE_H__
#include <iostream>
#include <fstream>
#include "AmaProduct.h"
#include "Date.h"

namespace sict{
  class AmaPerishable:public AmaProduct{
	  Date expiry_;
  public:
	  AmaPerishable();
	  const Date& expiry()const;
	  void expiry(const Date &value);
	  std::fstream& store(std::fstream& file, bool addNewLine = true)const;
	  std::fstream& load(std::fstream& file);
	  std::ostream& write(std::ostream& os, bool linear=true)const;
	  std::istream& read(std::istream& istr);
  };
}
#endif
