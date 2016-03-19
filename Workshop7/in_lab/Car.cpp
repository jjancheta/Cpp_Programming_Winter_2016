// OOP244 Workshop 7: Inheritance & Virtual Functions 
// File: Car.cpp
// Version: 1.0
// Date: 2016/03/15
// Author: ANCHETA, Jesus Jr
// ID# : 017 433 152
// Email: jjancheta@myseneca.ca

#include "Car.h"

namespace sict{
	//protected functions
	void Car::speed(int value){
		speed_ = value;
		if (value > maxSpeed()){
			maxSpeed_ = value;
		}
		else if (value < 0){
			maxSpeed_ = 0;
		}
	}

	int Car::maxSpeed()const{
		return maxSpeed_;
	}

	//public functions
	int Car::speed() const{
		return speed_;
	}

	//constructor
	Car::Car(int maxSpeed){
		maxSpeed_ = maxSpeed;
		speed_ = 0;
	}

}