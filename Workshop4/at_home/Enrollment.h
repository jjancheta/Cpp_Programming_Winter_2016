// OOP244 Workshop 4: Constructors
// File: Enrollment.h
// Version: 1.0
// Date: Feb 09, 2016
// Author: ANCHETA, JESUS JR
// ID #: 017 433 152
// Email: jjancheta@myseneca.ca

#ifndef SICT_ENROLLMENT_H_
#define SICT_ENROLLMENT_H_

namespace sict{

	class Enrollment{
	private:
		char name_[31];
		char code_[11];
		int year_;
		int semester_;
		int slot_;
		bool enrolled_;
	public:
		Enrollment();
		Enrollment(const char* courseName, const char* courseCode, int courseYear, int courseSemester, int courseTime);
		void display(bool nameOnly = false)const;
		bool isValid()const;
		void setEmpty();
		bool isEnrolled() const;
		void set(const char* name, const char* code, int year, int semester, int time, bool enrolled = false);
		bool hasConflict(const Enrollment &other) const;
		void withdraw();
		int enrol(const Enrollment* enrollments, int size);


	};
}

#endif


