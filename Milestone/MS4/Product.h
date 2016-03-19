// Name:  ANCHETA, Jesus Jr.
// ID: 017 433 152
// Email: JJANCHETA@myseneca.ca
// Filename: Streamable.h
// Milestone: 4


#ifndef SICT__PRODUCT_H_
#define SICT__PRODUCT_H_
#include <iostream>
#include "Streamable.h"
#include "general.h"

namespace sict{
	class Product :public Streamable{
		char sku_[MAX_SKU_LEN + 1];
		char* name_;
		double price_;
		bool taxed_;
		int quantity_;
		int quantityNeeded_;
	public:
		//Constructors & Destructor
		Product();
		Product(const char* sku, const char* name, 
			double price=0, int neededQty=0, bool taxed = true);  //defaulted price & neededQty to zero
		virtual ~Product();

		//Copy & Assignment Operators
		Product(const Product& copy1);
		Product& operator=(const Product& copy2);
		
		//Setters
		void sku(const char* sku_var);
		void name(const char* name_var);
		void price(double price_var);
		void quantity(int quantity_var);
		void qtyNeeded(int qtyNeeded_var);
		void taxed(bool taxed_var);
		
		//Getters
		const char* sku() const;
		const char* name() const;
		double price() const;
		bool taxed() const;
		int quantity() const;
		int qtyNeeded() const;
		double cost() const;
		bool isEmpty() const;
		
		//Member Operators Overload
		bool operator == (const char* sku);
		int operator += (int addProductQty);
		int operator -= (int lessProductQty);
		
	};
	
		//Non-Member Operator Overload
		double operator+=(double& value, const Product& x);
		
		//Non-Member IO Operators
		std::istream& operator >>(std::istream& in, Product& input);
		std::ostream& operator <<(std::ostream& out, Product& output);


}

#endif