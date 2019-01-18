#ifndef _W7_TAXABLEPRODUCT_H_
#define _W7_TAXABLEPRODUCT_H_

#include "Product.h"
#define HST 0.13
#define PST 0.08

namespace w7 {
	class TaxableProduct : public Product {
	private:
		char tax;
		const double taxRate[2] = { HST, PST };
	public:
		TaxableProduct(long tempProductNumber, double tempCost, char tempTax);
		double getCharge() const;
		void display(std::ostream&) const;
		~TaxableProduct();
	};
}

#endif // !_W7_TAXABLEPRODUCT_H_
