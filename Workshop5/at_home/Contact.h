#ifndef SICT_CONTACT_H_
#define SICT_CONTACT_H_
#include "PhoneNumber.h"
namespace sict{
  class Contact{
    char name_[41];
    PhoneNumber* phoneNumber_;
    int _noPN;
    void setEmpty();
  public:
	Contact();									//default constructor
	Contact(const char* name, int numPhone);    //constructor with arguments
	Contact(const Contact& cCopy);				//copy constructor
	Contact& operator=(const Contact& C);       //assignment operator
	~Contact();								    //destructor
    void read();
    void display()const;
    bool isEmpty()const;
	void set(const Contact& phoneNumber);
  };

}

#endif