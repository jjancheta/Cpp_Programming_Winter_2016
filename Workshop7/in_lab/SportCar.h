// OOP244 Workshop 7: Inheritance & Virtual Functions 
// File: SportCar.h
// Version: 1.0
// Date: 2016/03/15
// Author: ANCHETA, Jesus Jr
// ID# : 017 433 152
// Email: jjancheta@myseneca.ca

#include <iostream>
#include "Car.h"

#ifndef SICT_SPORTCAR_H_
#define SICT_SPORTCAR_H_

namespace sict{
  class SportCar:public Car{
	  int noOfPassengers_;
  protected:
	  void speed(int value);
	  int maxSpeed()const;
  public:
	  SportCar();
	  SportCar(int maxSpeed, int noOfPassengers);
	  void accelerate();
	  void brake();
	  std::ostream& display(std::ostream& ostr) const;
  };
}
#endif