// OOP244 Workshop 4: Constructors
// File: Enrollment.h
// Version: 1.0
// Date: Feb 09, 2016
// Author: ANCHETA, JESUS JR
// ID #: 017 433 152
// Email: jjancheta@myseneca.ca

#include <iostream>
#include <cstring>
#include "Enrollment.h"
using namespace std;

namespace sict{
	Enrollment::Enrollment(){
		setEmpty();
	}

	Enrollment::Enrollment(const char* courseName, const char* courseCode, int courseYear, int courseSemester, int courseTime) {
		set(courseName, courseCode, courseYear, courseSemester, courseTime);
	}

	void Enrollment::set(const char* name, const char* code, int year, int semester, int time, bool enrolled){
		if (name && code && name[0] != 0 && code[0] != 0 && year >= 2015 &&
			(semester > 0 && semester < 4) && (time > 0 && time < 6)) {
			strcpy(name_, name);
			strcpy(code_, code);
			year_ = year;
			slot_ = time;
			semester_ = semester;
			enrolled_ = enrolled;
		}
		else {
			setEmpty();
		}

	}

	bool Enrollment::hasConflict(const Enrollment &other) const {
		bool conflict = false;
		if (year_ != 0 && semester_ != 0 && slot_ != 0){
			if (year_ == other.year_  && semester_ == other.semester_ && slot_ == other.slot_){
				conflict = true;
			}
		}
		return conflict;
	}

	void Enrollment::withdraw(){
		enrolled_ = false;
	}

	int Enrollment::enrol(const Enrollment* enrollments, int size){
		int i;
		int flag = 0;
		for (i = 0; i < size; i++){
			if (hasConflict(enrollments[i])){
				flag = i + 1;                        //should not return 0 element as it will be equal to enrolled flag as 0
				withdraw();
				i = size;
			}
			else{
				enrolled_ = true;
			}
		}
		return flag;
	}

	bool Enrollment::isValid()const{
		return name_ && name_[0];          //not safe empty state  = TRUE
	}

	void Enrollment::setEmpty(){
		name_[0] = 0;
		code_[0] = 0;
		year_ = 0;
		semester_ = 0;
		slot_ = 0;
		enrolled_ = false;
	}

	bool Enrollment::isEnrolled() const{
		return enrolled_;
	}


	void Enrollment::display(bool nameOnly)const{
		if (isValid()){
			cout << name_;
			if (!nameOnly){
				cout << endl << code_ << ", Year: " << year_ << " semester: " << semester_ << " Slot: " << slot_ << endl;
				cout << "Status: " << (isEnrolled() ? "E" : "Not e") << "nrolled." << endl;
			}
		}
		else{
			cout << "Invalid enrollment!" << endl;
		}
	}
}