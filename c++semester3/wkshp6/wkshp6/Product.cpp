#include "Product.h"
#include "TaxableProduct.h"

using namespace std;

namespace w7 {

	Product::Product() {
		productNumber = 0;
		cost = 0;
	}
	Product::Product(long tempProductNumber, double tempCost) {
		productNumber = tempProductNumber;
		cost = tempCost;
	}

	double Product::getCharge() const {
		return cost;
	}

	void Product::display(std::ostream & os) const {
		os << productNumber << setw(16) << fixed << setprecision(2) << cost;
	}

	Product::~Product() {
	}
	
	std::ostream& operator<<(std::ostream& os, const iProduct& p) {
		p.display(os);
		return os;
	}

	iProduct* readProduct(std::ifstream& fs) {

		int tempProductNumber;
		double tempCost;
		char tempTax;

		fs >> tempProductNumber;
		fs >> tempCost;

		tempTax = fs.get();

		if (tempTax == ' ') {
			fs >> tempTax;

			if (tempTax == 'H' || tempTax == 'P') {
				return new TaxableProduct(tempProductNumber, tempCost, tempTax);
			}
		}
		else {
			return new Product(tempProductNumber, tempCost);
		}
	}

}