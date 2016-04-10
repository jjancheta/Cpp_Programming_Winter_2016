// OOP244 Workshop 7: Inheritance & Virtual Functions 
// File: PickupTruck.h
// Version: 1.0
// Date: 2016/03/15
// Author: ANCHETA, Jesus Jr
// ID# : 017 433 152
// Email: jjancheta@myseneca.ca

#include <iostream>
#include "Car.h"

#ifndef SICT_PICKUPTRUCK_H_
#define SICT_PICKUPTRUCK_H_


namespace sict{
	class PickupTruck :public Car{
		int loadAmount_;
		char loadedMaterial_[31];
	public:
		PickupTruck();
		void load(const char* loadedMaterial, int loadAmount);
		void unload();
		bool isEmpty()const;
		void accelerate();
		void brake();
		std::ostream& display(std::ostream& ostr) const;
	};
}

#endif