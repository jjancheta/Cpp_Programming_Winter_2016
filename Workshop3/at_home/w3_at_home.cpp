// OOP244 Workshop 3: Dynamic Memory
// File	w3_at_home.cpp
// Version 1.0
// Date: Feb 02, 2016
// Author: ANCHETA, JESUS JR
// ID #: 017 433 152
// Email: jjancheta@myseneca.ca// Date	
///////////////////////////////////////////////////////////


#include <iostream>
#include <cstring>
#include "Weather.h"
using namespace std;
using namespace sict;
double findLow(const char* date, const Weather *data, int dataSize);

int main(){
  int i; //  loop counter
  int n; //the count of days worth of weather
  // create the weather pointer here
  Weather* weather;

  cout << "Weather Data\n";
  cout << "=====================" << endl;
  cout << "Days of Weather: ";
  cin >> n;
  cin.ignore();
  // allocate dynamic memory here
  weather = new Weather[n];

  for (i = 0; i < n; i++){
    char date_description[7];
    double high;
    double low;

    // accept user input for weather
	cout << "Enter date: ";
	cin >> date_description;
	cout << "Enter high: ";
	cin >> high;
	cout << "Enter low : ";
	cin >> low;
	weather[i].set(date_description, high, low);

  }
  cout << endl
    << "Weather report:" << endl
    << "Date        high  low" << endl
    << "======================" << endl;

  for (i = 0; i < n; i++){
    weather[i].display();
  }

  

  char query[7];
  cout << endl << "Enter the date you are looking for: ";
  cin.ignore();
  cin.getline(query, 7, '\n');
  //accept user input for the date to find
  //(in this example stored in char query[7])
  // and display the found low temprature.


 double low = findLow(query, weather, n);
 cout << "Low temperature: " << low << endl;
  // deallocate dynamic memory here
  delete[] weather;
  weather = nullptr;
  
  return 0;

}

double findLow(const char* date, const Weather* data, int dataSize){
	int i;
	double lowTemp = 0.0;
	for (i = 0; i < dataSize; i++){
		if (!strcmp(date,data[i].date())){
			lowTemp = data[i].low();
		}
	}
	return lowTemp;

}