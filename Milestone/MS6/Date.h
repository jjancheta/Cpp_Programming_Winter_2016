// Name:  ANCHETA, Jesus Jr.
// ID: 017 433 152
// Email: JJANCHETA@myseneca.ca
// Filename: Date.h
// Milestone: 1


#ifndef SICT_DATE_H__
#define SICT_DATE_H__
#include <iostream>

namespace sict{
	#define NO_ERROR 0
	#define CIN_FAILED 1
	#define YEAR_ERROR 2
	#define MON_ERROR 3
	#define DAY_ERROR 4

  class Date{
	  private:
		  int year_;
		  int mon_;
		  int day_;
		  int readErrorCode_;
		  int value()const;
		  void errCode(int errorCode);
	  public:
		  Date();
		  Date(int year, int mon, int day);
		  bool operator==(const Date& D)const; 
		  bool operator!=(const Date& D)const; 
		  bool operator<(const Date& D)const; 
		  bool operator>(const Date& D)const; 
		  bool operator<=(const Date& D)const; 
		  bool operator>=(const Date& D)const;
		  int errCode()const;
		  bool bad()const;
		  std::istream& read(std::istream& istr);
		  std::ostream& write(std::ostream& ostr)const;
		  int mdays()const;
  };

  std::ostream& operator<<(std::ostream& ostr, const Date& out);
  std::istream& operator>>(std::istream& istr, Date& in);

}
#endif