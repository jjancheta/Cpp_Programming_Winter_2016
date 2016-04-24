#include <cstring>
#include <iostream>
#include "String.h"

using namespace std;

namespace sict{
  //private functions
	void String::deallocate(){
	  delete[] data_;
	  data_ = nullptr;
	  memSize_ = 0;
	 }
	void String::allocate(int memsize){
	  deallocate();
	  data_ = new char[memSize_ = memsize];
	  //initialize first element
	  data_[0] = '\0';

	}
	
	void String::init(const char* str, int memSize){
	  data_ = nullptr;
	  len_ = strlen(str);
	  if (memSize < len_ + 1){
		  memSize = len_ + 1;
	  }
	  allocate(memSize);
	  strcpy(data_, str);
	  data_[len_ + 1] = '\0';
	 }

  //constructors and destructors
	  String::String(){
		  data_ = nullptr;
		  memSize_ = 0;
		  len_ = 0;
	  }
	  String::String(const char* str, int memsize){
		  init(str, memsize);
	  }
	  String::~String(){
		  delete[] data_;
	  }

	  //copy and assignment operators
	  String::String(const String& S){
		  *this = S;
	  }
	  String& String::operator=(const String& S){
		  if (this != &S){
			  init(S.data_, S.memSize_);
		  }
		  return *this;
	  }

	  //public member functions
	void String::resize(int newsize){
		  int i;
		  char* temp;
		  temp = nullptr;
		  temp = new char[newsize];
		  temp[0] = '\0';          //initialize first element
		  if (data_){
			  for (i = 0; (i < newsize -1 && data_[i] != '\0'); i++){
				  temp[i] = data_[i];
			  }
			  temp[i] = '\0';
		  }
		  allocate(newsize);
		  if (temp[0] != '\0'){      //nothing to copy
			  strcpy(data_, temp);
		  }
		  len_ = strlen(data_);
	}

	  int String::length()const{
		  return len_;
	  }

	  int String::memSize()const{
		  return memSize_;
	  }


	  //IO member functions
	istream& String::read(istream& istr){
	  char c;
	  int i = 0;
	  for (i = 0; (c = istr.get() != '\n'); i++){
		  if (i == memSize_ - 1){
			  len_ = i;
			  resize(memSize_ + ExpansionSize);
		  }
		  data_[i] = c;
	  }
	  data_[len_ = i] = 0;
	  return istr;
  }

  // operator overloads
	  String& String::operator+=(const char* str){
		  int strLength = strlen(str);
		  if (memSize_ < (len_ + strLength + 1)){
			  resize(strLength + len_ + 1);
		  }
		  strcat(data_, str);
		  len_ = strlen(data_);
		  return *this;
	  }

	  String& String::operator+=(String& s){
		  *this += s.data_;
		  return *this;
	  }

	  String String::operator+(const String& s)const{
		  String temp;
		  temp.allocate(500);
		  temp += this->data_;
		  temp += " ";
		  temp += s.data_;
		  temp.len_ = strlen(temp.data_ + 1);
		  return temp;
	  }
	
	  String& String::operator++(){     //pre-fix operator
		  char temp[500];
		  strcpy(temp, " ");
		  strcat(temp, data_);
		  strcpy(data_, temp);
		  len_ = strlen(data_);
		  return *this;
	  }

	  String String::operator++(int){    //post-fix operator
		  String temp = *this;
		  temp += " ";
		  return *this;
	  }

	  char& String::operator[](int index){
		  if (index > memSize_ - 1){
			  resize(index + ExpansionSize);
		  }
		  return data_[index];
	  }
	  String::operator int()const{
		  return strlen(data_);
	  }

	  String::operator const char *()const{		 
			  return data_;         	
	  }
	  
	  ostream& String::display(ostream& ostr) const{
		  if (data_ != nullptr){
			  ostr << data_;
		  }
		  return ostr;
	  }


	//IO Non-member opertors
	  ostream& operator<<(ostream& ostr, const String& s){
		  return s.display(ostr);  
		 
	  }
	  istream& operator>>(istream& istr, String &s){ 
		  return s.read(istr);
	  }

}