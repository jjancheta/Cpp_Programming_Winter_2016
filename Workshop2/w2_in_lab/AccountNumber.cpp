// OOP244 Workshop 2: Compound types and privacy
// File	AccountNumber.cpp
// Version 1.0
// Date	2016/01/14
// Author	Ancheta, Jesus Jr.
// Description
// ?????????????????????
//
//
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
	void AccountNumber::name(const char name[]){
		strcpy(_name, name);
	};

	void AccountNumber::accountNumber(int bankCode, int branchCode, int accountNumber){
		_bankCode = bankCode;
		_branchCode = branchCode;
		_accountNumber = accountNumber;
		_validAccNumber = AccountNumber::isValid();

	};
	
	void AccountNumber::display() const{
		if (AccountNumber::_validAccNumber)
			cout << "Name: " << _name << ", Account number: " << _bankCode << "-"
			<< _branchCode << "-" << _accountNumber << endl;
		else
			cout << _name << " does not have a valid account number." << endl;
	};
	
	bool AccountNumber::isValid() const{
		bool checkAccount;
		checkAccount = (_bankCode >= MIN_BANKCODE && _bankCode <= MAX_BANKCODE) &&
			(_branchCode >= MIN_BRANCHCODE && _branchCode <= MAX_BRANCHCODE) &&
			(_accountNumber >= MIN_ACCNO && _accountNumber <= MAX_ACCNO);
		return checkAccount;
	};


}