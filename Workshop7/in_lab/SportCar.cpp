// OOP244 Workshop 7: Inheritance & Virtual Functions 
// File: SportCar.cpp
// Version: 1.0
// Date: 2016/03/15
// Author: ANCHETA, Jesus Jr
// ID# : 017 433 152
// Email: jjancheta@myseneca.ca


#include "SportCar.h"

namespace sict{
	//protected functions
	void SportCar::speed(int value){
		Car::speed(value);
	}

	int SportCar::maxSpeed()const{
		return Car::maxSpeed();
	}

	//public functions
	void SportCar::accelerate(){
		speed(Car::speed() + 40);
	}

	void SportCar::brake(){
		speed(Car::speed() - 10);
	}

	std::ostream& SportCar::display(std::ostream& ostr) const{
		ostr << "This sport car is carrying " << noOfPassengers_ << " passengers";
		
		if (Car::speed()){
				ostr << " and is traveling at a speed of " << Car::speed() << " km/h.";
		}
		else {
				ostr << " and is parked.";
		}
		return ostr;
	}

	//Constructors
	SportCar::SportCar(){
		noOfPassengers_ = 1;
	}

	SportCar::SportCar(int maxSpeed, int noOfPassengers) :Car(maxSpeed){
		noOfPassengers_ = noOfPassengers;
	}

}