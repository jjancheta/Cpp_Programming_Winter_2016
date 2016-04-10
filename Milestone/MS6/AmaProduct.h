// Name:  ANCHETA, Jesus Jr.
// ID: 017 433 152
// Email: JJANCHETA@myseneca.ca
// Filename: AmaProduct.h
// Milestone: 5


#ifndef SICT_AMAPRODUCT_H__
#define SICT_AMAPRODUCT_H__
#include <iostream>
#include <fstream>
#include "Product.h"
#include "ErrorMessage.h"


namespace sict{
  class AmaProduct : public Product{
  private:
	  char fileTag_;
	  char unit_[11];
  protected:
	  ErrorMessage err_;
  public:
	  AmaProduct(char fileTag = 'N');
	  const char* unit()const;
	  void unit(const char* value);
	  std::fstream& store(std::fstream& file, bool addNewLine = true)const;
	  std::fstream& load(std::fstream& file);
	  std::ostream& write(std::ostream& os, bool linear = true)const;
	  std::istream& read(std::istream& istr);
  };
}
#endif


