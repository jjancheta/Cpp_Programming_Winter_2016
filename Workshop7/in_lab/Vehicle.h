// OOP244 Workshop 7: Inheritance & Virtual Functions 
// File: Vehicle.h
// Version: 1.0
// Date: 2016/03/15
// Author: ANCHETA, Jesus Jr
// ID# : 017 433 152
// Email: jjancheta@myseneca.ca


#ifndef SICT_VEHICLE_
#define SICT_VEHICLE_

#include <iostream>

namespace sict{
  class Vehicle{
  public:
	  virtual void accelerate() = 0;
	  virtual void brake() = 0;
	  virtual std::ostream& display(std::ostream& ostr) const = 0;
  };
}
#endif