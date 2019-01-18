#include "CustomerOrder.h"
#include "Item.h"
#include "CustomerItem.h"
#include "Utilities.h"
#include <iomanip>
#include <iostream>
#include <vector>

size_t CustomerOrder::field_width;

CustomerOrder::CustomerOrder(const std::string & customerOrderInfo) {
	nOrders = 0;
	order = nullptr;

	Utilities utilitiesObj;
	std::string token;
	size_t position = 0;
	bool t = true;

	std::vector<std::string> v;
	while (t) {
		v.push_back(utilitiesObj.nextToken(customerOrderInfo, position, t));
	}
	order = new CustomerItem[v.size() - 2];
	nOrders = v.size() - 2;
	name = v[0];
	product = v[1];
	for (size_t i = 0; i < v.size() - 2; i++)
	{
		order[i] = CustomerItem(v[i+2]);
	}
	
	if (field_width < utilitiesObj.getFieldWidth()) {
		field_width = utilitiesObj.getFieldWidth();
	}
	
	//token = utilitiesObj.nextToken(customerOrderInfo, position, t);

	/*for (int i = 0; t; i++) {
		if (!token.empty()) {
			if (i == 0) {
				name = token;
			}
			else if (i == 1) {
				product = token;
			}
		}
		else {
			throw std::string("*** no token found before the delimiter ***");
		}
	}*/
	/*
	name = token;
	product = utilitiesObj.nextToken(customerOrderInfo, position, t);


	//allocate dynamic memory here
	if (nOrders != 0) {
		CustomerItem* tempCustomerItem = new CustomerItem[nOrders];
		for (unsigned int i = 0; i < nOrders; i++) {
			tempCustomerItem[i] = order[i];
		}
		delete[] order;
		order = new CustomerItem[++nOrders];
		for (unsigned int i = 0; i < (nOrders - 1); i++) {
			order[i] = tempCustomerItem[i];
		}
		delete[] tempCustomerItem;
		order[nOrders - 1] = CustomerItem(utilitiesObj.nextToken(customerOrderInfo, position, t));
	}
	else {
		order = new CustomerItem[++nOrders];
		order[nOrders - 1] = CustomerItem(utilitiesObj.nextToken(customerOrderInfo, position, t));
	}
	//allocate dynamic memory here

	*/

	
}

CustomerOrder::CustomerOrder(const CustomerOrder &) {
	throw std::string("Copy constructor should never be called as customer orders are not to be dublicated.");
}

CustomerOrder::CustomerOrder(CustomerOrder&& src) NOEXCEPT {
	*this = std::move(src);
}

CustomerOrder&& CustomerOrder::operator=(CustomerOrder&& src) NOEXCEPT {
	if (this != &src) {
		name = src.name;
		product = src.product;
		order = src.order;
		nOrders = src.nOrders;

		src.name.clear();
		src.product.clear();
		src.order = nullptr;
		src.nOrders = 0;
	}
	return std::move(*this);
}

CustomerOrder::~CustomerOrder() {
	delete[] order;
	order = nullptr;
}

unsigned int CustomerOrder::noOrders() const {
	return nOrders;
}

const std::string & CustomerOrder::operator[](unsigned int i) const {
	if (i > nOrders) {
		throw std::string("Index is out of bounds");
	}
	return order[i].getName();
}

void CustomerOrder::fill(Item & item) {
	for (unsigned int i = 0; i < nOrders; i++) {
		if (order[i].getName() == item.getName()) {
			order[i].fill(item.getCode());
			item++;
		}
	}
}

void CustomerOrder::remove(Item & item) {
	for (unsigned int i = 0; i < nOrders; i++) {
		if (order[i].getName() == item.getName()) {
			order[i].clear();
		}
	}
}

bool CustomerOrder::empty() const {
	if (name.empty() && product.empty() && !order && nOrders == 0) {
		return true;
	}
	else {
		return false;
	}
}

void CustomerOrder::display(std::ostream & os) const {
	os << std::left << std::setw(field_width) << name << " : " << std::setw(field_width) << product << std::endl;
	for (unsigned int i = 0; i < nOrders; i++) {
		order[i].display(os);
	}
}
