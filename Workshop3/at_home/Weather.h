// OOP244 Workshop 3: Dynamic Memory
// File: Weather.h
// Version: 1.0
// Date: Feb 02, 2016
// Author: ANCHETA, JESUS JR
// ID #: 017 433 152
// Email: jjancheta@myseneca.ca

#ifndef SICT_WEATHER_H_
#define SICT_WEATHER_H_

namespace sict{
	class Weather{
		char date_[7];
		double high_;
		double low_;
	public:
		void set(const char* inputDate, double inputHigh, double inputLow);
		void display() const;
		const char* date() const;
		double low() const;
	};
}
#endif