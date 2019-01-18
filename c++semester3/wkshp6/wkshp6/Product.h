#ifndef _W7_PRODUCT_H_
#define _W7_PRODUCT_H_

#include "iProduct.h"
#include <iostream>
#include <iomanip> 

namespace w7 {
	class Product : public iProduct {
	private:
		long productNumber;
		double cost;
	public:
		Product();
		Product(long tempProductNumber, double tempCost);
		double getCharge() const;
		void display(std::ostream&) const;
		~Product();
	};

}

#endif // !_W7_PRODUCT_H_