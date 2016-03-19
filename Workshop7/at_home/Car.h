// OOP244 Workshop 7: Inheritance & Virtual Functions 
// File: Car.h
// Version: 1.0
// Date: 2016/03/15
// Author: ANCHETA, Jesus Jr
// ID# : 017 433 152
// Email: jjancheta@myseneca.ca

#include "Vehicle.h"

#ifndef SICT_CAR_H_
#define SICT_CAR_H_


namespace sict{
  class Car : public Vehicle{
	  int speed_;
	  int maxSpeed_;
  protected:
	  void speed(int value);
	  int maxSpeed()const;
  public:
	  Car(int maxSpeed = 100);
	  int speed() const;
  };

 std::ostream& operator << (std::ostream& ostr, const Car& out);

}

#endif