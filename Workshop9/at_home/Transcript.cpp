// OOP244 Workshop 9: DMA and Classes Resources 
// File: Transcript.cpp
// Version: 1.0
// Date: 2016/03/29
// Author: ANCHETA, Jesus Jr
// ID# : 017 433 152
// Email: jjancheta@myseneca.ca


#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "Transcript.h"
using namespace std;

namespace sict{
	Transcript::Transcript(){
		stName_[0] = '\0';
		stNo_[0] = '\0';
		subs_ = nullptr;
		noOfSubs_ = 0;
	}
	Transcript::Transcript(const char* stname, const char* stno){
		strncpy(stName_, stname, sizeof(stName_));
		strncpy(stNo_, stno, sizeof(stNo_));
		subs_ = nullptr;
		noOfSubs_ = 0;
	}

	Transcript::Transcript(const Transcript& x){
		*this = x;
	}

	Transcript& Transcript::operator=(const Transcript& y){
		if (this != &y){
			strcpy(stName_, y.stName_);
			strcpy(stNo_, y.stNo_);
			subs_ = y.subs_;
			noOfSubs_ = y.noOfSubs_;
		}
		return *this;
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
		if (noOfSubs_ > 0){
			for (i = 0; i < noOfSubs_; i++){
				subs_[i].display(os);
				os << endl;
				temp += subs_[i].mark();
			}
			os << setfill(' ') << setw(70) << right << "GPA:" << " "
				<< fixed << setprecision(1) << temp.gpa() / noOfSubs_ << endl;

			Subject min, max;
			max = min = subs_[0];
			for (int i = 1; i < noOfSubjects(); i++){
				if (subs_[i].mark() < min.mark()) min = subs_[i];
				if (subs_[i].mark() > max.mark()) max = subs_[i];
			}
			os << "Best mark was in " << (const char*)max << endl << max << endl;
			os << "Worst mark was in " << (const char*)min << endl << min << endl;
		}
		else{
			os << endl << "***No Subject/s Available****" << endl;
		}
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

	std::istream& operator >> (std::istream& os, Transcript& in){
		return in.read(os);
	}

	std::istream& Transcript::read(std::istream& istr){
		cout << endl << "Student name: ";
		istr.getline(stName_, 81);
		cout << "Student Number: ";
		istr.getline(stNo_, 81);
		cout << "Number of subjects: ";
		istr >> noOfSubs_;
		
		subs_ = nullptr;
		subs_ = new Subject[noOfSubs_];
		
		int i;
		for (i = 0; i < noOfSubs_; i++){
			istr.ignore(2000, '\n');
			subs_[i].read(istr);
		}
		return istr;
	}

	
}
