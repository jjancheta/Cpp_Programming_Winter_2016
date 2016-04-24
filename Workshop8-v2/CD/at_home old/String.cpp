// OOP244 Workshop 8: DMA and Operator Overload 8.1
// File: String.cpp
// Version: 1.0
// Date: 2016/03/29
// Author: ANCHETA, Jesus Jr
// ID# : 017 433 152
// Email: jjancheta@myseneca.ca


#include <cstring>
#include <iostream>
#include "String.h"

using namespace std;

namespace sict{
  void String::deallocate(){
	  delete[] data_;
	  data_ = nullptr;
	  memSize_ = 0;
  }
  void String::allocate(int memsize){
	  deallocate();
	  data_ = new char[memSize_ = memsize];
  }

  void String::resize(int newsize){
	  int i;
	  char* temp;
	  temp = nullptr;
	  temp = new char[newsize];
	  if (data_){
		  for (i = 0; (i < newsize - 1 && data_[i] != '\0'); i++){
			  temp[i] = data_[i];
		  }
		  temp[i] = '\0';

	  }
	  allocate(newsize);
	  strcpy(data_, temp);
	  len_ = i;
  }

  String::String(){
	  data_ = nullptr;
	  memSize_ = 0;
	  len_ = 0;
  }

  void String::init(const char* str, int memSize){
	  data_ = nullptr;
	  len_ = strlen(str);
	  if (memSize < len_ + 1){
		  memSize = len_ + 1;
	  }
	  allocate(memSize);
	  strcpy(data_, str);
  }

  String::String(const char* str, int memsize){
	  init(str, memsize);
  }

  String::String(const String& S){
	  *this = S;
  }
  String& String::operator=(const String& S){
	  if (this != &S){
		  init(S.data_, S.memSize());
	  }
	  return *this;
  }


  String::~String(){
	  delete[] data_;
  }

  int String::length()const{
	  return len_;
  }

  int String::memSize()const{
	  return memSize_;
  }

  

  istream& String::read(istream& istr){
	  char c;
	  int i;
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
	  if ((memSize() + strLength) > memSize()){
		  resize(strLength + memSize());
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
	  String temp = *this;
	  temp += s;
	  return temp;
  }

  String& String::operator++(){
	  String& temp = *this;
	  strcat(" ", temp.data_);
	  return *this;
  }

  String String::operator++(int){
	  *this += " ";
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

  std::ostream& String::display(std::ostream& ostr) const{
	  ostr << data_;
	  return ostr;
  }
  
  //Non-member IO operators
  std::ostream& operator<<(std::ostream& ostr, String& s){
	  return s.display(ostr);
  }

  std::istream& operator>>(std::istream& istr, String &s){
	  return s.read(istr);
  }

}