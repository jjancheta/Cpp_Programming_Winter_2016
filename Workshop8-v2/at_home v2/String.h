#ifndef SICT_STRING_H_
#define SICT_STRING_H_
#include <iostream>
const int ExpansionSize = 500;
namespace sict{
  class String{
    char* data_;
    int memSize_;
    int len_;
    void deallocate();
    void allocate(int size);
    void init(const char* str, int memSize);
  public:
    void resize(int newsize);
    int memSize()const;

    String();
    String(const char* str, int memsize = 500);
    String(const String& S);
    String& operator=(const String& S);
    virtual ~String();

    int length()const;

    operator const char*()const;
    // IO
    std::istream& read(std::istream& istr = std::cin);
	std::ostream& display(std::ostream& ostr) const;
    
	// operators

    String& operator+=(const char* str);
    String& operator+=(String& s);
    String operator+(const String& s)const;
    String& operator++();
    String operator++(int); // <-- workshop 8.1

    char& operator[](int index);
    operator int()const;
	String& spaceBefore(String& x);

  };
  std::ostream& operator<<(std::ostream& ostr, const String &s);
  std::istream& operator>>(std::istream& istr, String &s);
}


#endif