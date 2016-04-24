// Name:  ANCHETA, Jesus Jr.
// ID: 017 433 152
// Email: JJANCHETA@myseneca.ca
// Filename: AmaPerishable.cpp
// Milestone: 5

#include <iostream>
#include <fstream>
#include <iomanip>
#include "AmaPerishable.h"
using namespace std;

namespace sict{
	AmaPerishable::AmaPerishable():AmaProduct('P'){	
	}
	
	const Date& AmaPerishable::expiry()const{
		return expiry_;
	}

	void AmaPerishable::expiry(const Date &value){
		expiry_ = value;  
	}

	fstream& AmaPerishable::store(fstream& file, bool addNewLine)const{
		AmaProduct::store(file,false);
		file << "," << expiry_ << endl;
		return file;
	}

	fstream& AmaPerishable::load(fstream& file){
		AmaProduct::load(file);
		file.ignore();
		expiry_.read(file);	
		return file;
	}
	
	ostream& AmaPerishable::write(ostream& os, bool linear)const{
		AmaProduct::write(os, linear);
		if (err_.isClear() && !isEmpty()){
			if (linear){
				os << expiry();
			}
			else{
				os << endl << "Expiry date: " << expiry();
			}
		}
		return os;
	}
	
	istream& AmaPerishable::read(istream& istr){
		AmaProduct::read(istr);
		if (err_.isClear() && !istr.fail()){
			Date tempDate;
			cout << "Expiry date (YYYY/MM/DD): ";
			istr >> tempDate;
			if (tempDate.bad()){
				switch (tempDate.errCode()){
					case CIN_FAILED:
						err_ = "Invalid Date Entry";
						break;
					case YEAR_ERROR:
						err_ = "Invalid Year in Date Entry";
						break;
					case MON_ERROR:
						err_ = "Invalid Month in Date Entry";
						break;
					case DAY_ERROR:
						err_ = "Invalid Day in Date Entry";
						break;
				}
				istr.setstate(ios::failbit);
				
			 }
			 else{
				expiry(tempDate);
			 }
		  }
		return istr;
	 }

}
