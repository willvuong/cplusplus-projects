#ifndef SICT_NONPERISHABLE_H__
#define SICT_NONPERISHABLE_H__

#include "Product.h"
#include "ErrorMessage.h"

namespace sict {	
	class NonPerishable : public Product {
		#define max_sku_length 7
		#define max_unit_length 10
		#define max_name_length 75
		#define taxRate 1.13
	private:
		char productType[2];
		char productSku[max_sku_length + 1];
		char* productName;
		char productUnit[max_unit_length + 1];
		int productQuantity;
		int quantityNeeded;
		double productPrice;
		bool taxable;
		ErrorMessage em;
	protected:
		void name(const char*);
		const char* name() const;
		double cost() const;
		void message(const char*);
		bool isClear() const;
	public:
		NonPerishable(char type = 0); 
		NonPerishable(const char* tempSku, const char* tempName, const char* tempUnit, int tempQuantity = 0, bool tempTaxable = true, double tempPrice = 0.0, int tempNeeded = 0);
		NonPerishable(const NonPerishable& np);
		NonPerishable& operator=(const NonPerishable& np);
		~NonPerishable();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		int operator+=(int);
		bool operator>(const Product&) const;
	};
	std::ostream& operator<<(std::ostream&, const Product&);
	std::istream& operator >> (std::istream&, Product&);
	double operator+=(double&, const Product&);
	Product* CreateProduct();
}
#endif