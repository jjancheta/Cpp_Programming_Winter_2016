// OOP244 Workshop 2: Compound types and privacy
// File	AccountNumber.cpp
// Version 1.0
// Date	2016/01/19
// Name: Ancheta, Jesus Jr.
// ID #: 017 433 152
// Email: jjancheta@myseneca.ca
// Description
// This file consists of several methods as below:
// 1. copies the values of the variables inputted in main function to the member variables of the class.
// 2. validates the account number with the predefined values in the class and displays account number if valid
//    else it will display an error message.	
///////////////////////////////////////////////////////////



#include <iostream>
#include <cstring>
using namespace std;
#include "AccountNumber.h"

namespace sict{
  // member functions' (methods') definition go here
	
	void AccountNumber::name(const char name[]){
		strcpy(_name, name);
	}

	void AccountNumber::accountNumber(int bankCode, int branchCode, int accountNumber){
		_bankCode = bankCode;
		_branchCode = branchCode;
		_accountNumber = accountNumber;
		_validAccNumber = isValid();

	}
	
	void AccountNumber::display() const{
		if (_validAccNumber){
			displayName();
			cout << ", ";
			displayNumber();
			cout << "\n";
		}
		else
			cout << _name << " does not have a valid account number." << endl;

	}

	void AccountNumber::display(bool display_name) const{
		if (_validAccNumber && !display_name){
			displayNumber();
			cout << "\n";
		}
		else
			cout << _name << " does not have a valid account number." << endl;
	}
	
	void AccountNumber::display(bool display_name, bool display_number) const{ 
		if (_validAccNumber && display_name && !display_number){
			displayName();
			cout << "\n";
		}
		else if (_validAccNumber && !display_name && !display_number)
			;
		else
			cout << _name << " does not have a valid account number." << endl;
	}
	
	bool AccountNumber::isValid() const{
		bool checkAccount;
		checkAccount = (_bankCode >= MIN_BANKCODE && _bankCode <= MAX_BANKCODE) &&
			(_branchCode >= MIN_BRANCHCODE && _branchCode <= MAX_BRANCHCODE) &&
			(_accountNumber >= MIN_ACCNO && _accountNumber <= MAX_ACCNO);
		return checkAccount;
	}

	void AccountNumber::displayName() const{
		cout << "Name: " << _name;
	}
	
	void AccountNumber::displayNumber() const{
		cout << "Account number: " << _bankCode << "-" << _branchCode << "-" << _accountNumber;
	}
}