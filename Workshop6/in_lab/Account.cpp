// OOP244 Workshop 6: operators 
// File: Account.cpp
// Version: 1.0
// Date: 2016/02/23
// Author: ANCHETA, Jesus Jr
// ID# : 017 433 152
// Email: jjancheta@myseneca.ca


#include <iomanip>
#include <iostream>
#include <cstring>
#include "Account.h"
using namespace std;
namespace sict{
	Account::Account(){
		name_[0] = 0;
		balance_ = 0;
	}
	Account::Account(double balance){
		name_[0] = 0;
		balance_ = balance;
	}
	Account::Account(const char name[], double balance){
		strncpy(name_, name, 40);
		name_[40] = 0;
		balance_ = balance;
	}
	Account& operator+(const Account& b, const Account& c){
		Account temp;
		Account& x = temp;
		x.balance_ = b.balance_ + c.balance_;
		return x;
	}
	Account& Account::operator=(const char* newname){
		strcpy(name_, newname);
		return *this;
	}
	Account& Account::operator+=(const Account& cb){
		if (this != &cb){
			balance_ += cb.balance_;
		}
		return *this;
	}
	ostream& operator<<(ostream& stream, const Account& abc){
		abc.display(false);
		return stream;
	}
	void Account::display(bool gotoNewline)const{
		cout << (name_[0] ? name_ : "No Name") << ": $" << setprecision(2) << fixed << balance_;
		if (gotoNewline) cout << endl;
	}
}


