// OOP244 Workshop 3: Dynamic Memory
// File: Weather.cpp
// Version: 1.0
// Date: Feb 02, 2016
// Author: ANCHETA, JESUS JR
// ID #: 017 433 152
// Email: jjancheta@myseneca.ca

#include <iostream>
using namespace std;
#include <cstring>
#include <iomanip>
#include "Weather.h"

namespace sict{
	// set
	void Weather::set(const char* inputDate, double inputHigh, double inputLow){
		strcpy(date_, inputDate);
		high_ = inputHigh;
		low_ = inputLow;
	}

	// display
	void Weather::display() const{
		cout << setfill('_') << setw(10) << left << date_
		     << setw(6) << fixed << setprecision(1) << right << high_
		     << setw(6) << fixed << setprecision(1) << right << low_ << endl;
	}

}