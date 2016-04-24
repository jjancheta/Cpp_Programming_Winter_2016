#include <cstring>
#include <iostream>
#include "String.h"

using namespace std;

namespace sict{
  void String::deallocate(){
  }
  void String::allocate(int memsize){
  }

  void String::resize(int memsize){
  }

  String::String(){
  }

  void String::init(const char* str, int memSize){
  }

  String::String(const char* str, int memSize){
  }

  String::String(const String& S){
  }
  String& String::operator=(const String& S){
  }


  String::~String(){
  }

  int String::length()const{
  }

  int String::memSize()const{
  }

  String::operator const char *()const{
  }

  istream& String::read(istream& istr){
  }

  // operator overloads


  String& String::operator+=(const char* str){
  }

  String& String::operator+=(String& s){
  }

  String& String::operator++(){
  }

  String& String::operator++(int){
  }

  char& String::operator[](int index){
  }
  String::operator int()const{
  }

  std::ostream& operator<<(std::ostream& ostr, const String &s){
  }
  std::istream& operator>>(std::istream& ostr, String &s){
  }

}