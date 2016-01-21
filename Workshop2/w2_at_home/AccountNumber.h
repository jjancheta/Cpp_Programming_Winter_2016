// OOP244 Workshop 2: Compound types and privacy
// File AccountNumber.h
// Version 1.0
// Date 2016/01/19
// Name: Ancheta, Jesus Jr.
// ID #: 017 433 152
// Email: jjancheta@myseneca.ca
// Description
// This file declares predefined values and a class (AccountNumber) which
// has private member variables and public member functions.
///////////////////////////////////////////////////////////



#ifndef SICT_ACCOUNTNUMBER_H_
#define SICT_ACCOUNTNUMBER_H_

namespace sict{
	// #define statements go here
	#define MAX_NAME_LENGTH 40
	#define	MIN_BANKCODE 100
	#define	MAX_BANKCODE 999
	#define	MIN_BRANCHCODE 1
	#define	MAX_BRANCHCODE 220
	#define	MIN_ACCNO 10000
	#define	MAX_ACCNO 99999

	// class declration goes here
	class AccountNumber{
		char _name[MAX_NAME_LENGTH + 1];
		int _bankCode;
		int _branchCode;
		int _accountNumber;
		bool _validAccNumber;
		void displayName() const;
		void displayNumber() const;
	public:
		void name(const char name[]);
		void accountNumber(int bankCode, int branchCode, int accountNumber);
		void display() const;
		void display(bool display_name) const;
		void display(bool display_name, bool display_number) const;
		bool isValid() const;

	};

}

#endif

