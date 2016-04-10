// Name:  ANCHETA, Jesus Jr.
// ID: 017 433 152
// Email: JJANCHETA@myseneca.ca
// Filename: Streamable.h
// Milestone: 3


#ifndef SICT__STREAMABLE_H_
#define SICT__STREAMABLE_H_
#include <iostream>
#include <fstream>

namespace sict{
  class Streamable{
  public:
	  virtual std::fstream& store(std::fstream& file, bool addNewLine = true)const = 0;
	  virtual std::fstream& load(std::fstream& file) = 0;
	  virtual std::ostream& write(std::ostream& os, bool linear = true)const = 0;
	  virtual std::istream& read(std::istream& is) = 0;
  };
}
#endif