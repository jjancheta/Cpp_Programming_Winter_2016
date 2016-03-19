// OOP244 Workshop 6: operators 
// File: Account.h
// Version: 1.0
// Date: 2016/02/25
// Author: ANCHETA, Jesus Jr
// ID# : 017 433 152
// Email: jjancheta@myseneca.ca


#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__
#include <iostream>
namespace sict{
  class Account{
    char name_[41];
    double balance_;
  public:
    Account();
    Account(double balance);
    Account(const char name[], double balance = 0.0);
	void display(bool gotoNewline = true)const;
	friend Account& operator+(const Account& b, const Account& c);
    double getBalance() const;
	Account& operator=(const char* newname);
	Account& operator+=(const Account& cb);		
  };
  std::ostream& operator<<(std::ostream& stream, const Account& abc);
  double operator+=(double& total, const Account& cba);
  
};

#endif

