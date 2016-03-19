// OOP244 Workshop 7: Inheritance & Virtual Functions 
// File: Driver.h
// Version: 1.0
// Date: 2016/03/15
// Author: ANCHETA, Jesus Jr
// ID# : 017 433 152
// Email: jjancheta@myseneca.ca

#ifndef SICT_DRIVER_H_
#define SICT_DRIVER_H_

#include "Car.h"

namespace sict{
	class Driver{
		char name_[31];
		Car& car_;
	public:
		Driver(const char* name, Car& cRef);
		void drive();
		void stop();
		void showStatus();
  };
	
}
#endif