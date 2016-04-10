// Name:  ANCHETA, Jesus Jr.
// ID: 017 433 152
// Email: JJANCHETA@myseneca.ca
// Filename: ErrorMessage.cpp
// Milestone: 2

#include <cstring>
#include <iostream>
#include "ErrorMessage.h"

namespace sict{
	//Default Constructor
	ErrorMessage::ErrorMessage(){
		message_ = nullptr;
	}
	
	//Constructor with 1 argument
	ErrorMessage::ErrorMessage(const char* errorMessage){
		message_ = nullptr;
		message(errorMessage);
	}

	//Virtual destructor
	ErrorMessage::~ErrorMessage(){
		delete[] message_;
	}
	
	//Modifier: sets the value of message_ data member using dynamic memory
	void ErrorMessage::message(const char* value){
		delete[] message_;
		message_ = new char[strlen(value) + 1];
		strcpy(message_, value);
	}
	
	//Operator= : clears dynamic memory and sets new value of message_ data member by dynamic memory
	ErrorMessage& ErrorMessage::operator=(const char* errorMessage){
		clear();
		message(errorMessage);
		return *this;
	}
	
	// Deallocates dynamic memory and sets message_ data member to nullptr
	void ErrorMessage::clear(){
		delete[] message_;
		message_ = nullptr;
	}
	
	//Checks if message_  data member is set to nullptr
	bool ErrorMessage::isClear() const{
		return message_ == nullptr;
	}
	
	//Returns the address of message_ data member
	const char* ErrorMessage::message() const{
		return message_;
	}
	
	//Output stream member function / cout
	std::ostream& ErrorMessage::write(std::ostream& ostr)const{
		if (!isClear()){
			ostr << message_;
		}
		return ostr;
	}
	
	//Operator << overload helper function / cout
	std::ostream& operator<<(std::ostream& ostr, const ErrorMessage& out){
		return out.write(ostr);
	}

}