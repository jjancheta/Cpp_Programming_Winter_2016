<<<<<<< HEAD
// Name:  ANCHETA, Jesus Jr.
// ID: 017 433 152
// Email: JJANCHETA@myseneca.ca
// Filename: Date.cpp
// Milestone: 1


#include <iomanip>
#include <iostream>
using namespace std;
#include "Date.h"
#include "general.h"
namespace sict{
	//Default constructor
	Date::Date(){
		year_ = 0;
		mon_ = 0;
		day_ = 0;
		readErrorCode_ = NO_ERROR;	
	}
	//Constructor with 3 arguments + readErrorCode = NO_ERROR
	Date::Date(int year, int mon, int day){
		year_ = year;
		mon_ = mon;
		day_ = day;
		readErrorCode_ = NO_ERROR;
	}
	//Logical operators
	bool Date::operator==(const Date& D)const{
		return value() == D.value();
	}
	
	bool Date::operator!=(const Date& D)const{
		return value() != D.value();
	}
	
	bool Date::operator<(const Date& D)const{
		return value() < D.value();
	}
	
	bool Date::operator>(const Date& D)const{
		return value() > D.value();
	}
	
	bool Date::operator<=(const Date& D)const{
		return value() <= D.value();
	}
	
	bool Date::operator>=(const Date& D)const{
		return value() >= D.value();
	}
	//Returns the value of readErrorCode_
	int Date::errCode()const{
		return readErrorCode_;
	}
	//Returns true if readErrorCode_ is not equal to zero
	bool Date::bad()const{
		return errCode() != 0;
	}
	//Output stream member function 
	ostream& Date::write(ostream& ostr)const{
		ostr << year_ << "/" << setw(2) << setfill('0') << mon_ << "/" 
			 << setw(2) << day_ << setfill(' ');
		return ostr;
	}
	//Output stream operator << as helper function
	ostream& operator<<(ostream& ostr, const Date& out){
		return out.write(ostr);
	}
	//Input stream member function
	istream& Date::read(istream& istr){
		char delimeter1;
		char delimeter2;
		istr >> setw(4) >> year_ >> setw(1) >> delimeter1 
			 >> setw(2) >> mon_  >>setw(1) >> delimeter2 >> setw(2)>> day_;

		if (istr.fail() || ((delimeter1 != '/' || delimeter2 != '/') &&
			(delimeter1 != '-' || delimeter2 != '-'))){
			readErrorCode_ = CIN_FAILED;
		}
		else if (year_ < MIN_YEAR || year_ > MAX_YEAR){
			readErrorCode_ = YEAR_ERROR;
		}
		else if (mon_ < 1 || mon_ > 12){
			readErrorCode_ = MON_ERROR;
		}
		else if (day_ < 1 || day_ > mdays()){
			readErrorCode_ = DAY_ERROR;
		}
		else{
			readErrorCode_ = NO_ERROR;
		}
		return istr;
	}
	//Input stream operator >> as helper function
	istream& operator>>(istream& istr, Date& in){
		return in.read(istr);
	}
	
	//Implemented member functions
	int Date::value()const{
		return year_ * 372 + mon_ * 31 + day_;
	}
	
	int Date::mdays()const{
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
		mon--;
		return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
	}
}
=======
// Name:  ANCHETA, Jesus Jr.
// ID: 017 433 152
// Email: JJANCHETA@myseneca.ca
// Filename: Date.cpp
// Milestone: 1


#include <iomanip>
#include <iostream>
using namespace std;
#include "Date.h"
#include "general.h"
namespace sict{
	//Default constructor
	Date::Date(){
		year_ = 0;
		mon_ = 0;
		day_ = 0;
		readErrorCode_ = NO_ERROR;	
	}
	//Constructor with 3 arguments + readErrorCode = NO_ERROR
	Date::Date(int year, int mon, int day){
		year_ = year;
		mon_ = mon;
		day_ = day;
		readErrorCode_ = NO_ERROR;
	}
	//Logical operators
	bool Date::operator==(const Date& D)const{
		return value() == D.value();
	}
	
	bool Date::operator!=(const Date& D)const{
		return value() != D.value();
	}
	
	bool Date::operator<(const Date& D)const{
		return value() < D.value();
	}
	
	bool Date::operator>(const Date& D)const{
		return value() > D.value();
	}
	
	bool Date::operator<=(const Date& D)const{
		return value() <= D.value();
	}
	
	bool Date::operator>=(const Date& D)const{
		return value() >= D.value();
	}
	//Returns the value of readErrorCode_
	int Date::errCode()const{
		return readErrorCode_;
	}
	//Returns true if readErrorCode_ is not equal to zero
	bool Date::bad()const{
		return errCode() != 0;
	}
	//Output stream member function 
	ostream& Date::write(ostream& ostr)const{
		ostr << year_ << "/" << setw(2) << setfill('0') << mon_ << "/" 
			 << setw(2) << day_ << setfill(' ');
		return ostr;
	}
	//Output stream operator << as helper function
	ostream& operator<<(ostream& ostr, const Date& out){
		return out.write(ostr);
	}
	//Input stream member function
	istream& Date::read(istream& istr){
		char delimeter1;
		char delimeter2;
		istr >> setw(4) >> year_ >> setw(1) >> delimeter1 
			 >> setw(2) >> mon_  >>setw(1) >> delimeter2 >> setw(2)>> day_;

		if (istr.fail() || ((delimeter1 != '/' || delimeter2 != '/') &&
			(delimeter1 != '-' || delimeter2 != '-'))){
			readErrorCode_ = CIN_FAILED;
		}
		else if (year_ < MIN_YEAR || year_ > MAX_YEAR){
			readErrorCode_ = YEAR_ERROR;
		}
		else if (mon_ < 1 || mon_ > 12){
			readErrorCode_ = MON_ERROR;
		}
		else if (day_ < 1 || day_ > mdays()){
			readErrorCode_ = DAY_ERROR;
		}
		else{
			readErrorCode_ = NO_ERROR;
		}
		return istr;
	}
	//Input stream operator >> as helper function
	istream& operator>>(istream& istr, Date& in){
		return in.read(istr);
	}
	
	//Implemented member functions
	int Date::value()const{
		return year_ * 372 + mon_ * 31 + day_;
	}
	
	int Date::mdays()const{
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
		mon--;
		return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
	}
}
>>>>>>> 462f745acb960edd2a588aeb146f428a36c4dc0d
