// Name:  ANCHETA, Jesus Jr.
// ID: 017 433 152
// Email: JJANCHETA@myseneca.ca
// Filename: AidApp.h
// Milestone: 6

#ifndef SICT__AIDAPP_H_
#define SICT__AIDAPP_H_
#include <iostream>
#include <fstream>
#include "Product.h"

namespace sict{
	class AidApp{
		char filename_[256];
		Product* product_[MAX_NO_RECS];
		std::fstream datafile_;
		int noOfProducts_;
		AidApp(const AidApp& copy) = delete;
		AidApp& operator=(const AidApp& A) = delete;
		void pause()const;
		int menu();
		void loadRecs();
		void saveRecs();
		void listProducts()const;
		int SearchProducts(const char* sku)const;
		void addQty(const char* sku);
		void addProduct(bool isPerishable);
	public:
		AidApp(const char* filename);
		int run();
	};
}

#endif