#include "OrderManager.h"
#include "CustomerOrder.h"
#include "ItemManager.h"
#include "Item.h"
#include <algorithm>


CustomerOrder && OrderManager::extract() {
	return std::move(*this->end());
}

void OrderManager::validate(const ItemManager & itemManager, std::ostream & os) {
	std::vector<CustomerOrder>::const_iterator iterator;
	for (iterator = this->begin(); iterator != this->end(); iterator++){
		for (unsigned int i = 0; i < iterator->noOrders(); i++) {
			auto validate = [&](const Item& item) {
				return !item.getName().compare((*iterator)[i]);
			};
			if (std::find_if(itemManager.cbegin(), itemManager.cend(), validate) == itemManager.cend()) {
				os << (*iterator)[i] << " is not available " << std::endl;
			}
		}
	}
}

void OrderManager::display(std::ostream & os) const {
	/*std::vector<CustomerOrder> customerOrders;
	std::vector<CustomerOrder>::iterator customerOrderIterator;

	for (customerOrderIterator = customerOrders.begin; customerOrderIterator != customerOrders.end; customerOrderIterator++) {
		customerOrderIterator->display(os);
	}*/

	std::vector<CustomerOrder>::const_iterator customerOrderIterator;
	for (customerOrderIterator = this->begin(); customerOrderIterator != this->end(); customerOrderIterator++) {
		customerOrderIterator->display(os);
	}
}
