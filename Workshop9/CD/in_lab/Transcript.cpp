// OOP244 Workshop 9: DMA and Classes Resources 
// File: Transcript.cpp
// Version: 1.0
// Date: 2016/03/29
// Author: ANCHETA, Jesus Jr
// ID# : 017 433 152
// Email: jjancheta@myseneca.ca


#include <iostream>
#include <cstring>
#include <iomanip>
#include "Transcript.h"
using namespace std;

namespace sict{
	Transcript::Transcript(const char* stname, const char* stno){
		strncpy(stName_, stname, sizeof(stName_));
		strncpy(stNo_, stno, sizeof(stNo_));
		subs_ = nullptr;
		noOfSubs_ = 0;
	}

	Transcript& Transcript::operator+=(const Subject& S){
		Subject* temp;
		int i;
		temp = new Subject[noOfSubs_ + 1];
		for (i = 0; i < noOfSubs_; i++){
			temp[i] = subs_[i];
		}
		noOfSubs_++;
		temp[noOfSubs_-1] = S;
		delete[] subs_;
		subs_ = new Subject[noOfSubs_];
		for (i = 0; i < noOfSubs_; i++){
			subs_[i] = temp[i];
		}
		return *this;
	}

	Subject& Transcript::operator[](int index){
		return subs_[index % noOfSubs_];
	
	}

	std::ostream& Transcript::display(std::ostream& os)const{
		int i = 0;
		Mark temp;
		os << "Student Name: " << stName_ << endl 
			<< "Student Number: " << stNo_ << endl;
		for (i = 0; i < noOfSubs_; i++){
			subs_[i].display(os);
			os << endl;
			temp += subs_[i].mark();
		}
		
		os << setfill(' ') << setw(70) << right << "GPA:" << " " 
			<< fixed << setprecision(1) << temp.gpa() / noOfSubs_ << endl;
		return os;
	}

	Transcript::~Transcript(){
		delete[] subs_;
	}

	int Transcript::noOfSubjects()const{
		return noOfSubs_;
	}

	std::ostream& operator << (std::ostream& os, const Transcript& out){
		return out.display(os);
	}

}
