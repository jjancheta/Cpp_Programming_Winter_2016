// OOP244 Workshop 7: Inheritance & Virtual Functions 
// File: Driver.cpp
// Version: 1.0
// Date: 2016/03/15
// Author: ANCHETA, Jesus Jr
// ID# : 017 433 152
// Email: jjancheta@myseneca.ca


#include <iostream>
#include <cstring>
#include "Driver.h"
using namespace std;
namespace sict{
	Driver::Driver(const char* name, Car& cRef):car_(cRef){
		strncpy(name_, name, 30);
		name_[30] = '\0';
	}
	void Driver::drive(){
		car_.accelerate();
		car_.brake();
		showStatus();
		
	}
	void Driver::stop(){
		while (car_.speed()){
			car_.brake();
		}
		showStatus();
	
	}

	void Driver::showStatus(){
		cout << name_ << " is driving this car." << endl;
		cout << car_ << endl;
	}
}