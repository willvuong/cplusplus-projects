#include "Sale.h"

using namespace std;

namespace w7 {

	Sale::Sale(const char * filename) {
		ifstream f;
		f.open(filename);

		if (f.is_open() && !f.eof()) {
			while (!(f.peek() == EOF)) {
				products.push_back(readProduct(f));
			}
		}
		else {
			cout << "fail" << endl;
		}
		f.close();
	}
	
	void Sale::display(std::ostream & os) const {
		double customerTotal = 0;
		os << "Product No      Cost Taxable" << endl;

		for (auto i = products.begin(); i != products.end(); i++) {
			os << **i << endl;
		}

		for (int i = 0; i < products.size(); i++) {
			customerTotal += products[i]->getCharge();
		}

		os << "     Total  " << customerTotal << endl;
	}
	
	Sale::~Sale() {
		for (auto p : products) delete p;
	}

}