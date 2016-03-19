#include <cstring>
#include <iostream>
#include "Contact.h"
using namespace std;

namespace sict{

	Contact::Contact(){
		setEmpty();
	}
	
	Contact::Contact(const char* name, int numPhone){
		phoneNumber_ = nullptr;
		phoneNumber_ = new PhoneNumber[numPhone];
		strncpy(name_, name, 40);
		name_[40] = '\0';
		_noPN = numPhone;
	}

	Contact::Contact(const Contact& cCopy){
		set(cCopy);
	}
	
	Contact& Contact::operator=(const Contact& C){
		if (this != &C){
			delete[] phoneNumber_;
			set(C);
		}
		return *this;
	}

	Contact::~Contact(){
		delete[] phoneNumber_;

	}

	void Contact::set(const Contact& phoneCopy){
		int i;
		if (phoneCopy.isEmpty()){
			setEmpty();
		}
		else {
			strcpy(name_, phoneCopy.name_);
			_noPN = phoneCopy._noPN;
			phoneNumber_ = nullptr;
			phoneNumber_ = new PhoneNumber[_noPN];
			for (i = 0; i < _noPN; i++){
				phoneNumber_[i] = phoneCopy.phoneNumber_[i];
			}
		}
	}

  void Contact::display()const{
    //display the name and go to new line
	  cout << name_ << endl;

    // loop through elements of phoneNumber_ up to _noPN and display them one by one
		  int i;
		  for (i = 0; i < _noPN; i++){
			  phoneNumber_[i].display();
		  }
	  
    // draw a 40 char line using '-' and go to new line
	  cout << "----------------------------------------" << endl;

  }

  void Contact::read(){
    cout << "Contact Name: ";
    cin.getline(name_, 41, '\n');
    cout << "Please enter " << _noPN << " phone numbers: " << endl;
    for (int i = 0; i < _noPN; i++){
      cout << i + 1 << ": ";
      phoneNumber_[i].read();
    }
  }


  bool Contact::isEmpty()const{
    return phoneNumber_ == nullptr;
  }
  void Contact::setEmpty(){
    name_[0] = 0;
    _noPN = 0;
    phoneNumber_ = nullptr;// same as phoneNumber_ = (PhoneNumber*)0;
  }
}