// Name:  ANCHETA, Jesus Jr.
// ID: 017 433 152
// Email: JJANCHETA@myseneca.ca
// Filename: AmaProduct.cpp
// Milestone: 5

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "AmaProduct.h"
using namespace std;

namespace sict{
	//Constructor
	AmaProduct::AmaProduct(char fileTag){
		fileTag_ = fileTag;
	}

	const char* AmaProduct::unit()const{
		return unit_;
	}

	void AmaProduct::unit(const char* value){
		strncpy(unit_, value, 10);       
		unit_[10] = '\0';
	}

	std::fstream& AmaProduct::store(std::fstream& file, bool addNewLine)const{
		file << fileTag_ << "," << sku() << "," << name() << "," << price() << ","
			<< taxed() << "," << quantity() << "," << unit() << "," << qtyNeeded();
		if (addNewLine){
			file << endl;
		}
		return file;
	}

	std::fstream& AmaProduct::load(std::fstream& file){
		char tempSku[MAX_SKU_LEN + 1];
		char tempName[1000];
		char tempUnit[11];
		bool tempTaxed;
		double tempPrice;
		int tempQuantity;
		int tempQtyNeeded;

		file.getline(tempSku, MAX_SKU_LEN, ',');
		sku(tempSku);
		file.getline(tempName, 1000, ',');
		name(tempName);
		file >> tempPrice;
		price(tempPrice);
		file.ignore();
		file >> tempTaxed;
		taxed(bool(tempTaxed));
		file.ignore();
		file >> tempQuantity;
		quantity(tempQuantity);
		file.ignore();
		file.getline(tempUnit, 11, ',');
		unit(tempUnit);
		file >> tempQtyNeeded;
		qtyNeeded(tempQtyNeeded);
		return file;
	}

	std::ostream& AmaProduct::write(std::ostream& os, bool linear)const{
		if (err_.isClear()){
			char tempName[21];
			strncpy(tempName, name(), 20);
			tempName[20] = '\0';
			
			if (linear){
				os << setw(MAX_SKU_LEN) << left << sku() << "|"
					<< setw(20) << left << tempName << "|"
					<< setw(7) << fixed << right << setprecision(2) << cost() << "|"
					<< setw(4) << quantity() << "|"
					<< setw(10) << left << unit_ << "|"
					<< setw(4) << right << qtyNeeded() << "|";
			}
			else{
				os << "Sku: " << sku() << endl
					<< "Name: " << name() << endl
					<< "Price: " << fixed << setprecision(2) << price() << endl
					<< "Price after tax: ";
					if (taxed()){
						os << fixed << setprecision(2) << cost();
					}
					else{
						os << "N/A";
					}
					os << endl << "Quantity On Hand: " << quantity() << " " << unit_ << endl
					<< "Quantity Needed: " << qtyNeeded();
			}
		}
		else{
			os << err_;	
		}
		return os;
	}

	std::istream& AmaProduct::read(std::istream& istr){
		char tempSku[100];  
		char tempName[1000];
		char tempUnit[10000];
		char tempTaxed;
		double tempPrice;
		int tempQuantity;
		int tempQtyNeeded;

		if (!istr.fail()){
			err_.clear();
			cout << "Sku: ";
			istr.getline(tempSku,100);
			cout << "Name: ";
			istr.getline(tempName,1000);
			cout << "Unit: ";
			istr.getline(tempUnit,1000);
			cout << "Taxed? (y/n): ";
			istr.get(tempTaxed);
			if (toupper(tempTaxed) == 'Y' || toupper(tempTaxed) == 'N'){
				istr.ignore(2000, '\n');
			}
			else{
				err_.message("Only (Y)es or (N)o are acceptable");
				istr.setstate(ios::failbit);
			}
			
			cout << "Price: ";
			istr >> tempPrice;

			if (istr.fail() && err_.isClear()){
				err_.message("Invalid Price Entry");
			}

			if (err_.isClear()){
				cout << "Quantity On hand: ";
				istr >> tempQuantity;
			}
			
			if (istr.fail() && err_.isClear()){
				err_.message("Invalid Quantity Entry");
			}

			if (err_.isClear()){
				cout << "Quantity Needed: ";
				istr >> tempQtyNeeded;
			}

			if (istr.fail() && err_.isClear()){
				err_.message("Invalid Quantity Needed Entry");
			}

			if (!istr.fail()){
				sku(tempSku);
				name(tempName);
				unit(tempUnit);
				taxed(toupper(tempTaxed) == 'Y' ? true : false);
				price(tempPrice);
				quantity(tempQuantity);
				qtyNeeded(tempQtyNeeded);
			}

		}
		
		return istr;
	}

}