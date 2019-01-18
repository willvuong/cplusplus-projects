#include "TaxableProduct.h"

using namespace std;

namespace w7 {

	TaxableProduct::TaxableProduct(long tempProductNumber, double tempCost, char tempTax) : Product(tempProductNumber, tempCost) {
		//Product(tempProductNumber, tempCost);
		tax = tempTax;
	}

	double TaxableProduct::getCharge() const {
		double tempTax = 1;

		if (tax == 'H') {
			tempTax += taxRate[0];
		}
		else {
			tempTax += taxRate[1];
		}

		return Product::getCharge() * tempTax;
	}

	void TaxableProduct::display(std::ostream & os) const {
		Product::display(os);
		if (tax == 'H') {
			os << " HST";
		}
		else {
			if (tax == 'P') {
				os << " PST";
			}
		}
	}

	TaxableProduct::~TaxableProduct() {
	}

}