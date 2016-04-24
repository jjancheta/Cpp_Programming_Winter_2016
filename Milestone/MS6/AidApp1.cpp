// Name:  ANCHETA, Jesus Jr.
// ID: 017 433 152
// Email: JJANCHETA@myseneca.ca
// Filename: AidApp.cpp
// Milestone: 6

#include <iostream>
#include <iomanip>
#include <cstring>
#include "AidApp.h"
#include "Product.h"
#include "AmaProduct.h"
#include "AmaPerishable.h"
#include "Sort.h"
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
		cout << "Press Enter to continue..." << endl;
		cin.ignore(1000, '\n');
	}

	void AidApp::loadRecs(){
		int readIndex = 0;
		char id;
		fstream datafile_(filename_, ios::in);
		if (datafile_.fail()){
			datafile_.clear();
			datafile_.close();
			fstream datafile_(filename_, ios::out);
			datafile_.close();
		}
		else{
			while(readIndex < MAX_NO_RECS && !datafile_.fail()){
				id = 'x';
				delete product_[readIndex];
				id = datafile_.get();
				if (id == 'N'){
					product_[readIndex] = new AmaProduct;
				}
				else if (id == 'P'){
					product_[readIndex] = new AmaPerishable;		
				}
					
				if (id == 'N' || id == 'P'){
					datafile_.ignore();
					product_[readIndex]->load(datafile_);
					readIndex++;
					datafile_.ignore(1000, '\n');		
				}	
			} 
			datafile_.close();
			noOfProducts_ = readIndex;
		}

	}

	void AidApp::saveRecs(){
		int i;
		fstream datafile_(filename_, ios::out);
		if (datafile_.is_open()){
			for (i = 0; i < noOfProducts_; i++){
				product_[i]->store(datafile_);
			}
		}
		datafile_.close();
	}

	void AidApp::listProducts()const{
		int i;
		double totalCost = 0;
		int count = 0;
		
		cout << endl << " Row | SKU    | Product Name       | Cost  | QTY| Unit     |Need| Expiry   " << endl
		 	 << "-----|--------|--------------------|-------|----|----------|----|----------" << endl;
	
		for (i = 0; i < noOfProducts_; i++){
			cout << right << setw(4) << i + 1 << " | " << *product_[i] << endl;
			count++;
			if (count == 10){
				pause();
				count = 0;
			}
			totalCost += *product_[i];
		}
		cout << "---------------------------------------------------------------------------" << endl
			<< "Total cost of support: $" << fixed << setprecision(2) << totalCost << endl << endl;

	}

	int AidApp::SearchProducts(const char* sku)const{
		int i;
		int index = -1;
		for (i = 0; i < noOfProducts_; i++){
			if (!strcmp(product_[i]->sku(),sku)){
				index = i;
				i = noOfProducts_;
			}
		}
		return index;
	}

	void AidApp::addQty(const char* sku){
		int index = SearchProducts(sku);
		if (index == -1){
			cout << endl << "Not Found!" << endl;
		}
		else{
			cout << endl;
			product_[index]->write(cout, false) << endl;
			int qtyPurchased;
			cout << endl << "Please enter the number of purchased items: ";
			cin >> qtyPurchased;
			if (cin.fail()){
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid quantity value!" << endl;
			}
			else{
				int extra = qtyPurchased - (product_[index]->qtyNeeded() - product_[index]->quantity());		
				if (extra > 0){
					*product_[index] += (qtyPurchased - extra);
					cout << "Too many items; only " << (product_[index]->qtyNeeded() - product_[index]->quantity())
						<< " is needed, please return the extra " << extra << " items." << endl;
				}
				else{
					*product_[index] += qtyPurchased;
				}
				saveRecs();
				cout << endl << "Updated!" << endl << endl;
			}
			
		}
		
	}

	void AidApp::addProduct(bool isPerishable){
		delete product_[noOfProducts_];
		if (isPerishable){	
			product_[noOfProducts_] = new AmaPerishable;
		}
		else{
			product_[noOfProducts_] = new AmaProduct;
		}
		cout << endl;
		product_[noOfProducts_]->read(cin);
		if (cin.fail()){
			cout << *product_[noOfProducts_] << endl;
			cin.clear();
		}
		else{
			noOfProducts_ += 1;
			saveRecs();
		}
		cout << endl << "Product added" << endl << endl;
		cin.ignore(1000, '\n');
	}

	int AidApp::menu(){
		int select;
		cout << "Disaster Aid Supply Management Program" << endl
			<< "1- List products" << endl
			<< "2- Display product" << endl
			<< "3- Add non-perishable product" << endl
			<< "4- Add perishable product" << endl
			<< "5- Add to quantity of purchased products" << endl
			<< "6- Update product quantity" << endl       // extra challenge
			<< "7- Delete droduct" << endl               //extra challenge 
			<< "8- Sort Products" << endl                 //extra challenge
			<< "0- Exit program" << endl << "> ";
		cin >> select;

		if (cin.fail() || select < 0 || select > 8){
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
				case 1:                     //1- List products
					listProducts();
					pause();
					break;
				case 2:                    //2- Display product
					cout << endl << "Please enter the SKU: ";
					cin.getline(sku,MAX_SKU_LEN,'\n');
					index = SearchProducts(sku);
					if (index != -1){
						cout << endl;
						product_[index]->write(cout, false);
						cout << endl << endl;
					}
					else{
						cout << endl << "Not Found!" << endl;
					}
					pause();
					break;
				case 3:	                   //3- Add non - perishable product
					addProduct(false);     
					pause();
					break;
				case 4:
					addProduct(true);     //4- Add perishable product
					break;
				case 5:                   //5- Add to quantity of purchased products
					cout << endl << "Please enter the SKU: ";
					cin.getline(sku, MAX_SKU_LEN,'\n');
					addQty(sku);
					break;
				case 6:                  //6- Update product quantity
					cout << endl << "Please enter the SKU: ";
					cin.getline(sku, MAX_SKU_LEN, '\n');
					index = SearchProducts(sku);
					if (index != -1){
						cout << endl;
						product_[index]->write(cout, false);
						cout << endl << endl;
						updateProductQty(index);
					}
					else{
						cout << endl << "Not Found!" << endl << endl;
					}
					break;
				
				case 7:                  //7- Delete product
					cout << endl << "Deleting product, Please enter the SKU: ";
					cin.getline(sku, MAX_SKU_LEN + 1, '\n');
					index = SearchProducts(sku);
					if (index != -1){
						/*product_[index]->write(cout,false) << endl;
						cout << endl << "Confirm to delete? Y/N ";
						char confirm;
						confirm = cin.get();
						if (toupper(confirm) == 'Y'){*/
							deleteProduct(index);
						//}
					}
					else{
						cout << endl << "Not Found!" << endl << endl;
					}
					break;
				case 8:
					sortProduct();
					break;
				case -1:                 //Invalid selection
					cout << "===Invalid Selection, try again.===" << endl;
					pause();
					break;
			}
		} while (select);               // 0- Exit program (false)
		cout << endl << "Goodbye!!" << endl;
		return 0;
	}

	void AidApp::deleteProduct(const int index){
		int i;
		char id;
		//store products to temporary file excluding selected product to delete
		//e.g. index + 1 to number of products
		fstream tempFile("temp.txt", ios::out|ios::trunc);
		int start = index + 1;   
		if (tempFile.is_open()){
			for (i = start; i < noOfProducts_; i++){
				product_[i]->store(tempFile);
			}
		}
		tempFile.close();
		
		//load products and overwrite the original position of the product being deleted
		if (start != noOfProducts_){
			fstream F("temp.txt", ios::in);
			for (i = index; i < noOfProducts_ - 1; i++){
				delete product_[i];
				F.get(id);
				if (id == 'N'){
					product_[i] = new AmaProduct;
				}
				else if (id == 'P'){
					product_[i] = new AmaPerishable;
				}
				if (id == 'P' || id == 'N'){
					F.ignore();
					product_[i]->load(F);
					F.ignore(1000, '\n');
				}
			}
			F.close();
		}
		else{
			delete product_[start];
			product_[start] = nullptr;
		}
		noOfProducts_ = noOfProducts_ - 1;
		saveRecs();
		cout << endl << "Deleted!" << endl << endl;
	}

	void AidApp::updateProductQty(const int index){
		int newQty;
		cout << "Please enter the new item quantity: ";
		cin >> newQty;
		if (cin.fail()){
			cout << endl << "Invalid Quantity value!" << endl << endl;
			cin.clear();
		}
		else if (newQty < 0 || newQty > product_[index]->qtyNeeded()){
			cout << endl << "Invalid Quantity value, please enter a value betweeen 0 and "
				<< product_[index]->qtyNeeded() <<"."<< endl << endl;
		}
		else{
			product_[index]->quantity(newQty);
			saveRecs();
			cout << "Item quantity is set to " << product_[index]->quantity() << "."<<endl << endl;
		}
		cin.ignore(1000, '\n');
	}

	void AidApp::sortProduct(){
		sort(product_, noOfProducts_);
		saveRecs();
		cout << endl << "Sorted!" << endl << endl;
	}
	
}