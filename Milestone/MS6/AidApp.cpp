// Name:  ANCHETA, Jesus Jr.
// ID: 017 433 152
// Email: JJANCHETA@myseneca.ca
// Filename: AidApp.cpp
// Milestone: 6

#include <iostream>
#include <iomanip>
#include "AidApp.h"
#include "Product.h"
#include "AmaProduct.h"
#include "AmaPerishable.h"
using namespace std;

namespace sict {
	AidApp::AidApp(const char* filename){
		int i;
		strcpy(filename_, filename);
		for (i = 0; i < MAX_NO_RECS; i++){
			product_[i] = nullptr;
		}
		noOfProducts_ = 0;
		loadRecs();
	}
	
	void AidApp::pause()const{
		cout << "Press Enter to continue...";
		cin.ignore(1000, '\n');
	}

	void AidApp::loadRecs(){
		int readIndex = 0;
		char id;
		fstream datafile_(filename_,ios::in);
		if (datafile_.fail()){
			datafile_.clear();
			datafile_.close();
			fstream datafile_(filename_, ios::out);
			datafile_.close();
		}
		else{
			while (!datafile_.fail()){
				delete[] product_[readIndex];
				datafile_.get(id);
				if (id == 'N'){
					product_[readIndex]= new AmaProduct;
				}
				else if (id == 'P'){
					product_[readIndex] = new AmaPerishable;
				}
				datafile_.ignore();
				product_[readIndex][0].load(datafile_);  
				readIndex++;
				datafile_.ignore(100, '\n');
			}
			
			noOfProducts_ = readIndex-1;
			datafile_.close();
		}

	}

	void AidApp::saveRecs(){
		int i;
		fstream datafile_(filename_, ios::out);
		if (datafile_.is_open()){
			for (i = 0; i < noOfProducts_; i++){
				product_[i][0].store(datafile_);
			}
		}
		datafile_.close();
	}

	void AidApp::listProducts()const{
		int i;
		double totalCost = 0;
		int count = 0;
		
		cout << " Row | SKU    | Product Name       | Cost  | Qty| Unit     |Need| Expiry   " << endl
		 	 << "-----|--------|--------------------|-------|----|----------|----|----------" << endl;
	
		for (i = 0; i < noOfProducts_; i++){
			cout << right << setw(4) << i + 1 << " | " << product_[i][0] << endl;
			count++;
			if (count == 10){
				pause();
				count == 0;
			}
			totalCost += product_[i][0];
		}
		cout << "-------------------------------------------------------------------------------" << endl
			<< "Total Cost of Support: $" << fixed << setprecision(2) << totalCost << endl;

	}

	int AidApp::SearchProducts(const char* sku)const{
		int i;
		int index = -1;
		for (i = 0; i < noOfProducts_; i++){
			if (!strcmp(product_[i][0].sku(),sku)){
				index = i;
				i = noOfProducts_;
			}
		}
		return index;
	}

	void AidApp::addQty(const char* sku){
		int index = SearchProducts(sku);

		if (index == -1){
			cout << "Not Found!" << endl;
		}
		else{
			product_[index][0].write(cout, false) << endl;
			int qtyPurchased;
			cout << "Please enter number of purchased items: ";
			cin >> qtyPurchased;
			if (cin.fail()){
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid quantity value!" << endl;
			}
			else{
				int extra = qtyPurchased - (product_[index][0].qtyNeeded() - product_[index][0].quantity());		
				if (extra > 0){
					product_[index][0]+=(qtyPurchased - extra);
					cout << "Too many items; only " << product_[index][0].qtyNeeded()
						<< " is needed, please return the extra " << extra << " items." << endl;
				}
				else{
					product_[index][0]+= qtyPurchased;
				}
				saveRecs();
				cout << "Updated!" << endl;
			}
			
		}
		
	}

	void AidApp::addProduct(bool isPerishable){
		delete[] product_[noOfProducts_];
		if (isPerishable){	
			product_[noOfProducts_] = new AmaPerishable;
		}
		else{
			product_[noOfProducts_] = new AmaProduct;
		}
		cin >> product_[noOfProducts_][0];
		if (cin.fail()){
			cout << product_[noOfProducts_][0] << endl;
			cin.clear();
		}
		else{
			noOfProducts_ += 1;
			saveRecs();
		}
		cin.ignore(1000, '\n');
	}

	int AidApp::menu(){
		int select;
		cout << "Disaster Aid Supply Management Program" << endl
			<< "1- List products" << endl
			<< "2- Display product" << endl
			<< "3- Add non - perishable product" << endl
			<< "4- Add perishable product" << endl
			<< "5- Add to quantity of purchased products" << endl
			<< "0- Exit program" << endl << "> ";
		cin >> select;

		if (cin.fail() || select < 0 || select > 5){
			select = -1;
		}
		cin.ignore(1000, '\n');
		return select;
	}

	int AidApp::run(){
		int select;
		char sku[MAX_SKU_LEN + 1];
		int index;
		do {
			select = menu();
			switch (select){
				case 1:
					listProducts();
					pause();
					break;
				case 2:
					cout << "Please enter the SKU: ";
					cin.getline(sku,MAX_SKU_LEN+1,'\n');
					index = SearchProducts(sku);
					if (index != -1){
					   product_[index][0].write(cout,false) << endl;
					}
					else{
						cout << "Not Found!" << endl;
					}
					pause();
					break;
				case 3:
					addProduct(false);     //non-perishable
					pause();
					break;
				case 4:
					addProduct(true);     //perishable
					pause();
					break;
				case 5:
					cout << "Please enter the SKU: ";
					cin.getline(sku, MAX_SKU_LEN,'\n');
					addQty(sku);
					pause();
					break;
				case -1:
					cout << "===Invalid Selection, try again.===" << endl;
					pause();
					break;
			}
		} while (select);
		cout << "Goodbye!!" << endl;
		return 0;
	}
}
