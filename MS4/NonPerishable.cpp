#include "NonPerishable.h"
using namespace std;

namespace sict {

	void NonPerishable::name(const char * str) {
		if (productName != nullptr)
			delete[] productName;
		productName = new char[strlen(str) + 1];
		if (str != nullptr) {
			strcpy(productName, str);
		}
	}

	const char * NonPerishable::name() const {
		if (strcmp(productName, "") == 0) {
			return nullptr;
		}
		else {
			return productName;
		}
	}

	double NonPerishable::cost() const {
		if (taxable == true) {
			return productPrice * taxRate;
		}
		else return productPrice;
	}

	void NonPerishable::message(const char * msg) {
		em.message(msg);
	}

	bool NonPerishable::isClear() const {
		return em.isClear();
	}

	NonPerishable::NonPerishable(char type) {
		if (type != 0) {
			productType[0] = type;
		}
		productSku[0] = 0;
		productName = nullptr;
		productUnit[0] = 0;
		productQuantity = 0;
		quantityNeeded = 0;
		productPrice = 0;
		taxable = 0;
	}

	NonPerishable::NonPerishable(const char * tempSku, const char * tempName, const char * tempUnit, int tempQuantity, bool tempTaxable, double tempPrice, int tempNeeded) {
		productName = nullptr;
		strcpy(productSku, tempSku);
		name(tempName);
		strcpy(productUnit, tempUnit);
		productQuantity = tempQuantity;
		taxable = tempTaxable;
		productPrice = tempPrice;
		quantityNeeded = tempNeeded;
	}
	NonPerishable::NonPerishable(const NonPerishable& np) {
		*this = np;
	}

	NonPerishable & NonPerishable::operator=(const NonPerishable & np) {
		if (this != &np) {
			productName = nullptr;
			strcpy(this->productSku, np.productSku);
			strcpy(this->productType, np.productType);
			name(np.productName);
			strcpy(this->productUnit, np.productUnit);
			this->productQuantity = np.productQuantity;
			this->taxable = np.taxable;
			this->productPrice = np.productPrice;
			this->quantityNeeded = np.quantityNeeded;
		}
		return *this;
	}

	NonPerishable::~NonPerishable() {
		productName = nullptr;
		delete[] productName;
	}

	std::fstream & NonPerishable::store(std::fstream & file, bool newLine) const {
		file << NonPerishable() << ',' << productType << ',' << productSku << ',' << productName << ',' << productUnit <<
			',' << productQuantity << ',' << quantityNeeded << ',' << productPrice << ',' << taxable;

		if (newLine == true) {
			file << endl;
		}
		return file;
	}

	std::fstream & NonPerishable::load(std::fstream & file) {
		NonPerishable temp;
		file >> temp;
		//temp.operator=;
		return file;
	}

	std::ostream & NonPerishable::write(std::ostream & os, bool linear) const {
		if (linear == true) {
			os.setf(std::ios::left);
			os.width(max_sku_length);
			os << productSku << '|';
			os.setf(std::ios::left);
			os.width(20);
			os << productName << '|';
			os.setf(std::ios::right);
			os.setf(std::ios::fixed);
			os.width(7);
			os.precision(2);
			os << productPrice << '|';
			os.setf(std::ios::right);
			os.width(4);
			os << productQuantity << '|';
			os.unsetf(std::ios::right);
			os.width(10);
			os << productUnit << '|';
			os.setf(std::ios::right);
			os.width(4);
			os << quantityNeeded << '|';
		}
		else {
			os << "Sku: " << productSku << endl;
			os << "Name: " << productName << endl;
			os << "Price: " << productType << endl;
			if (taxable == true) {
				os << "Price after tax: " << cost() << endl;
			}
			else {
				os << "Price after tax: " << "N/A" << endl;
			}
			os << "Quantity On Hand: " << productQuantity << endl;
			os << "Quantity Needed:" << quantityNeeded << endl;
		}
		return os;
	}

	std::istream & NonPerishable::read(std::istream & is) {
		cout << "Sku: ";
		is >> productSku;
		cout << endl << "Name";
		is >> productName;
		cout << endl << "Unit";
		is >> productUnit;

		cout << endl << "Taxed? (y/n): ";
		is >> taxable;
		if (taxable != 'Y' || taxable != 'y' || taxable != 'N' || taxable != 'n') {
			cout << "Only (Y)es or (N)o are acceptable";
			is.setstate(std::ios::failbit);
			em.message("Only (Y)es or (N)o are acceptable");
		}

		cout << endl << "Price";
		is >> productPrice;
		if (productPrice < 0) {
			cout << "Invalid Price Entry";
			em.message("Invalid Price Entry");
		}

		cout << endl << "Quantity on hand: ";
		is >> productQuantity;
		if (productQuantity < 0) {
			cout << "Invalid Quantity Entry";
			em.message("Invalid Quantity Entry");
		}

		cout << endl << "Quantity Needed";
		is >> quantityNeeded; {
			if (quantityNeeded < 0) {
				cout << "Invalid Quantity Needed Entry";
				em.message("Invalid Quantity Needed Entry");

			}
		}
		return is;
	}


	bool NonPerishable::operator==(const char * tempSku) const {
		if (strcmp(productSku, tempSku) == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	double NonPerishable::total_cost() const {
		return cost()*quantity();
	}

	void NonPerishable::quantity(int q) {
		productQuantity = q;
	}

	bool NonPerishable::isEmpty() const {
		if (strcmp(productSku, "") == 0 && productName == nullptr && strcmp(productUnit, "") == 0 &&
			productQuantity == 0 && quantityNeeded == 0 && productPrice == 0 && taxable == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	int NonPerishable::qtyNeeded() const {
		return quantityNeeded;
	}

	int NonPerishable::quantity() const {
		return productQuantity;
	}

	bool NonPerishable::operator>(const char * tempSku) const {
		if (tempSku > productSku) {
			return true;
		}
		else {
			return false;
		}
	}

	int NonPerishable::operator+=(int tempQuantity) {
		if (tempQuantity > 0) {
			productQuantity += tempQuantity;
			return quantity();
		}
		else {
			return quantity();
		}
	}

	bool NonPerishable::operator>(const Product & p) const {
		if (productName > p.name()) {
			return true;
		}
		else {
			return false;
		}
	}

	//helpers

	std::ostream& operator<<(std::ostream& ostr, const Product& p) {
		return p.write(ostr, true);
	}

	std::istream& operator >> (std::istream& istr, Product& p) {
		return p.read(istr);
	}

	double operator+=(double& d, const Product& p) {
		double temp = 0.0;
		d += p.total_cost();
		temp = d;
		return temp;

	}

	Product* CreateProduct() {
		NonPerishable* tempNP = nullptr;
		tempNP = new NonPerishable;
		return tempNP;
	}

}