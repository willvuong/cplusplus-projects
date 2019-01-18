#ifndef _W7_SALE_H_
#define _W7_SALE_H_

#include "TaxableProduct.h"
#include <vector>

namespace w7 {
	class Sale {
	private:
		std::vector<iProduct*> products;
	public:
		Sale(const char* filename);
		void display(std::ostream& os) const;
		~Sale();
	};
}

#endif // !_W7_SALE_H_
