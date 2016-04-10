// OOP244 Workshop 9: DMA and Classes Resources 
// File: Transcript.h
// Version: 1.0
// Date: 2016/03/29
// Author: ANCHETA, Jesus Jr
// ID# : 017 433 152
// Email: jjancheta@myseneca.ca


#ifndef SICT_TRANSCRIPT_H_
#define SICT_TRANSCRIPT_H_

#include <iostream>
#include "Subject.h"

namespace sict{
	class Transcript{
		char stName_[81];
		char stNo_[10];
		Subject* subs_;
		int noOfSubs_;
	public:
		Transcript(const char* stname, const char* stno);
		Transcript& operator+=(const Subject& S);
		Subject& operator[](int index);
		std::ostream& display(std::ostream& os)const;
		virtual ~Transcript();
		int noOfSubjects()const;
	};
	std::ostream& operator << (std::ostream& os, const Transcript& out);
}


#endif