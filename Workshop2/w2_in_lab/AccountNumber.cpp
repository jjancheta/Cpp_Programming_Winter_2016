// OOP244 Workshop 2: Compound types and privacy
// File	AccountNumber.cpp
// Version 1.0
// Date	2016/01/14
// Author	Ancheta, Jesus Jr.
// Description
// This file consists of several methods as below:
// 1. copies the values of the variables inputted in main function to the member variables of the class.
// 2. validates the account number with the predefined values in the class and displays account number if valid
//    else it will display an error message.	  
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		Reason
// 
///////////////////////////////////////////////////////////

// Name: Ancheta, Jesus Jr.
// ID #: 017 433 152
// Email: jjancheta@myseneca.ca

#include <iostream>
#include <cstring>
using namespace std;
#include "AccountNumber.h"

namespace sict{
	// member functions' (methods') definition go here
	
	//copy the value of name variable to the _name data variable of the class
	void AccountNumber::name(const char name[]){
		strcpy(_name, name);
	
	};

	//copy the values of account number variables to the account number variables of the class & _validAccNumber
	void AccountNumber::accountNumber(int bankCode, int branchCode, int accountNumber){
		_bankCode = bankCode;
		_branchCode = branchCode;
		_accountNumber = accountNumber;
		_validAccNumber = isValid();

	};
	
	//checks if _validAccNumber is valid and print messages accordingly
	void AccountNumber::display() const{
		if (_validAccNumber)
			cout << "Name: " << _name << ", Account number: " << _bankCode << "-"
			<< _branchCode << "-" << _accountNumber << endl;
		else
			cout << _name << " does not have a valid account number." << endl;
	
	};
	
	//verify account numbers if valid based on defined values
	bool AccountNumber::isValid() const{
		bool checkAccount;
		checkAccount = (_bankCode >= MIN_BANKCODE && _bankCode <= MAX_BANKCODE) &&
			           (_branchCode >= MIN_BRANCHCODE && _branchCode <= MAX_BRANCHCODE) &&
			           (_accountNumber >= MIN_ACCNO && _accountNumber <= MAX_ACCNO);
		return checkAccount;
	
	};


}