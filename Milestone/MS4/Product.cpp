// Name:  ANCHETA, Jesus Jr.
// ID: 017 433 152
// Email: JJANCHETA@myseneca.ca
// Filename: Streamable.h
// Milestone: 4

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Product.h"

namespace sict{
	//Constructors & Destructor
	Product::Product(){
		sku_[0] = 0;
		name_ = nullptr;
		price_ = 0;
		quantity_ = 0;
		quantityNeeded_ = 0;
		taxed_ = 0;
	}

	Product::Product(const char* sku, const char* name, double price,
		               int neededQty, bool taxed):quantity_(0){	
		this->sku(sku);
		this->name(name);
		this->price(price);
		this->qtyNeeded(neededQty);
		this->taxed(taxed);
	}

	Product::~Product(){
		delete[] name_;
	}
	
	Product::Product(const Product& copy1){
		*this = copy1;
	}
	
	//Copy & Assignment Operators
	Product& Product::operator=(const Product& copy2){
		if (this != &copy2){
			sku(copy2.sku());
			name(copy2.name());
			price(copy2.price());
			quantity(copy2.quantity());
			qtyNeeded(copy2.qtyNeeded());
			taxed(copy2.taxed());
		}
		return *this;
	}

	//Setters:
	void Product::sku(const char* sku_var){
		strcpy(sku_, sku_var);
	}
	void Product::name(const char* name_var){
		name_ = nullptr;
		name_ = new char[strlen(name_var) + 1];
		strcpy(name_, name_var);
	}
	void Product::price(double price_var){
		price_ = price_var;
	}
	void Product::quantity(int quantity_var){
		quantity_ = quantity_var;
	}
	void Product::qtyNeeded(int qtyNeeded_var){
		quantityNeeded_ = qtyNeeded_var;
	}
	void Product::taxed(bool taxed_var){
		taxed_ = taxed_var;
	}

	//Getters:
	const char* Product::sku() const{
		return sku_;                      
	}

	const char* Product::name() const{
		return name_;
	}

	double Product::price() const{
		return price_;
	}

	bool Product::taxed() const{
		return taxed_;
	}

	int Product::quantity() const{
		return quantity_;
	}

	int Product::qtyNeeded() const{
		return quantityNeeded_;
	}

	double Product::cost() const{
		double cost = 0;
		if (taxed()){
			cost = price() * (TAX + 1);
		}
		else{
			cost = price();
		}
		return cost;   
	}

	bool Product::isEmpty() const{
		return (!sku_[0] &&
		!name() &&
		!price() &&
		!quantity() &&
		!qtyNeeded() &&
		!taxed());	
	}

    //Member Operators
	bool Product::operator == (const char* sku){
		return (!strcmp(sku_, sku));
	}
	int Product::operator += (int sumProductQty){
		return quantity_ += sumProductQty;  
	}
	int Product::operator -= (int lessProductQty){
		return  quantity_ -= lessProductQty; 
	}
	
	//Non-Member Operator
	double operator+=(double& value, const Product& x){
		value += x.cost()*x.quantity();
		return value;
	}
	
	//Non-members IO Operators
	std::istream& operator >>(std::istream& in, Product& input){
		return input.read(in);	
	}
	
	std::ostream& operator <<(std::ostream& out, const Product& output){
		return output.write(out,true);
	}
	
}

