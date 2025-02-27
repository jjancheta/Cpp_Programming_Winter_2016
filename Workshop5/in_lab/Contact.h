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
	  Contact();
	  Contact(const char* name, int numPhone);
	  ~Contact();
    void read();
    void display()const;
    bool isEmpty()const;
  };

}

#endif